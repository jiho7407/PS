#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int sq = 100;
vector<int> bucket[3][sq];
int val[3][sq];
int N, Q;

void swp(int a, int b, int L, int R){
    // cout << "swap " << a << ' ' << b << ' ' << L << ' ' << R << '\n';
    int lsq = L/sq, rsq = R/sq;

    if(lsq == rsq){
        for(int i = L; i <= R; i++){
            swap(bucket[a][i/sq][i%sq], bucket[b][i/sq][i%sq]);
        }
        vector<pair<vector<int>, int>> v;
        rep(i, 0, 3) v.push_back({bucket[i][L/sq], i});
        sort(v.begin(), v.end());
        rep(i, 0, 3) val[v[i].second][L/sq] = i;
        return;
    }
    for(int i = L; i%sq != 0; i++) swap(bucket[a][i/sq][i%sq], bucket[b][i/sq][i%sq]);
    if(L%sq == 0){
        swap(val[a][lsq], val[b][lsq]);
        swap(bucket[a][lsq], bucket[b][lsq]);
    }
    for(int i = lsq+1; i < rsq; i++){
        swap(val[a][i], val[b][i]);
        swap(bucket[a][i], bucket[b][i]);
    }
    for(int i = rsq*sq; i <= R; i++) swap(bucket[a][i/sq][i%sq], bucket[b][i/sq][i%sq]);

    vector<pair<vector<int>, int>> v;
    if(L%sq != 0){
        rep(i, 0, 3) v.push_back({bucket[i][L/sq], i});
        sort(v.begin(), v.end());
        rep(i, 0, 3) val[v[i].second][L/sq] = i;
    }

    v.clear();
    rep(i, 0, 3) v.push_back({bucket[i][R/sq], i});
    sort(v.begin(), v.end());
    rep(i, 0, 3) val[v[i].second][R/sq] = i;
}

void query(int L, int R){
    vector<int> a, b, c;

    int lsq = L/sq, rsq = R/sq;
    if(lsq == rsq){
        for(int i = L; i <= R; i++){
            a.push_back(bucket[0][i/sq][i%sq]);
            b.push_back(bucket[1][i/sq][i%sq]);
            c.push_back(bucket[2][i/sq][i%sq]);
        }
    }
    else{
        for(int i = L; i%sq != 0; i++){
            a.push_back(bucket[0][i/sq][i%sq]);
            b.push_back(bucket[1][i/sq][i%sq]);
            c.push_back(bucket[2][i/sq][i%sq]);
        }
        if(L%sq == 0){
            a.push_back(val[0][lsq]);
            b.push_back(val[1][lsq]);
            c.push_back(val[2][lsq]);
        }
        for(int i = lsq+1; i < rsq; i++){
            a.push_back(val[0][i]);
            b.push_back(val[1][i]);
            c.push_back(val[2][i]);

        }
        for(int i = rsq*sq; i <= R; i++){
            a.push_back(bucket[0][i/sq][i%sq]);
            b.push_back(bucket[1][i/sq][i%sq]);
            c.push_back(bucket[2][i/sq][i%sq]);
        }
    }
    
    vector<pair<vector<int>, int>> v;
    v.push_back({a, 0});
    v.push_back({b, 1});
    v.push_back({c, 2});
    sort(v.begin(), v.end());

    // for(auto [a, b]: v){
    //     for(auto x: a) cout << x;
    //     cout << ' ' << b << '\n';
    // }

    if(v[0].second == 0){
        if(v[1].second == 1) return;
        else swp(1, 2, L, R);
    }
    else if(v[0].second == 1){
        swp(0, 1, L, R);
        if(v[2].second == 2) return;
        else swp(1, 2, L, R);
    }
    else{
        swp(0, 2, L, R);
        if(v[1].second == 1) return;
        else swp(1, 2, L, R);
    }
}

void solve(){ 
    // 입력
    cin >> N >> Q;
    assert(1 <= N && N <= 1e5);
    assert(1 <= Q && Q <= 1e5);
    rep(i, 0, 3){
        string S; cin >> S;
        rep(j, 0, N) bucket[i][j/sq].push_back(S[j]-'a');
    }

    // 중간파트 전처리
    rep(i, 0, N/sq+1){
        vector<pair<vector<int>, int>> v;
        rep(j, 0, 3) v.push_back({bucket[j][i], j});
        sort(v.begin(), v.end());
        rep(j, 0, 3) val[v[j].second][i] = j;
    }

    // 쿼리
    while(Q--){
        int L, R; cin >> L >> R;
        assert(1 <= L && L <= R && R <= N);
        L--; R--;
        query(L, R);
    }
    rep(i, 0, N) cout << (char)('a'+bucket[0][i/sq][i%sq]);
    cout << '\n';
    rep(i, 0, N) cout << (char)('a'+bucket[1][i/sq][i%sq]);
    cout << '\n';
    rep(i, 0, N) cout << (char)('a'+bucket[2][i/sq][i%sq]);
    cout << '\n';
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}