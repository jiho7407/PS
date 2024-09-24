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

const int sq = 320;
vector<int> bucket[3][sq];
int val[3][sq];

int N, Q;

void swp(int a, int b, int L, int R){
    // cout << "swap " << a << ' ' << b << '\n';
    int i = L, j = R;
    while(i <= j && i%sq != 0){
        swap(bucket[a][i/sq][i%sq], bucket[b][i/sq][i%sq]);
        i++;
    }
    while(i+sq <= j){
        swap(val[a][i/sq], val[b][i/sq]);
        swap(bucket[a][i/sq], bucket[b][i/sq]);
        i += sq;
    }
    while(i <= j){
        swap(bucket[a][i/sq][i%sq], bucket[b][i/sq][i%sq]);
        i++;
    }

    vector<pair<vector<int>, int>> v;
    rep(i, 0, 3) v.push_back({bucket[i][L/sq], i});
    sort(v.begin(), v.end());
    rep(i, 0, 3) val[i][L/sq] = v[i].second+10;

    v.clear();
    rep(i, 0, 3) v.push_back({bucket[i][R/sq], i});
    sort(v.begin(), v.end());
    rep(i, 0, 3) val[i][R/sq] = v[i].second+10;
}

void query(int L, int R){
    vector<int> a, b, c;

    int i = L, j = R;
    while(i <= j && i%sq != 0){
        a.push_back(bucket[0][i/sq][i%sq]);
        b.push_back(bucket[1][i/sq][i%sq]);
        c.push_back(bucket[2][i/sq][i%sq]);
        i++;
    }
    while(i+sq <= j){
        a.push_back(val[0][i/sq]);
        b.push_back(val[1][i/sq]);
        c.push_back(val[2][i/sq]);
        i += sq;
    }
    while(i <= j){
        a.push_back(bucket[0][i/sq][i%sq]);
        b.push_back(bucket[1][i/sq][i%sq]);
        c.push_back(bucket[2][i/sq][i%sq]);
        i++;
    }
    
    vector<pair<vector<int>, int>> v;
    v.push_back({a, 0});
    v.push_back({b, 1});
    v.push_back({c, 2});
    sort(v.begin(), v.end());
    // for(auto i:a) cout << i << ' ';
    // cout << '\n';
    // for(auto i:b) cout << i << ' ';
    // cout << '\n';
    // for(auto i:c) cout << i << ' ';
    // cout << '\n';
    // cout << v[0].second << ' ' << v[1].second << ' ' << v[2].second << '\n';

    if(v[0].second != 0){
        swp(0, v[0].second, L, R);
        if(v[1].second == 0) swap(v[0].second, v[1].second);
        else swap(v[0].second, v[2].second);
    }

    if(v[1].second != 1) swp(1, 2, L, R);


}

void solve(){ 
    // 입력
    cin >> N >> Q;
    rep(i, 0, 3){
        string S; cin >> S;
        rep(j, 0, N) bucket[i][j/sq].push_back(S[j]-'a');
    }

    // 중간파트 전처리
    rep(i, 0, sq){
        vector<pair<vector<int>, int>> v;
        rep(j, 0, 3) v.push_back({bucket[j][i], j});
        sort(v.begin(), v.end());
        rep(j, 0, 3) val[j][i] = v[j].second+10;
    }

    // 쿼리
    while(Q--){
        int L, R; cin >> L >> R;
        L--; R--;
        query(L, R);
        // rep(i, 0, N) cout << (char)('a'+bucket[0][i/sq][i%sq]);
        // cout << '\n';
        // rep(i, 0, N) cout << (char)('a'+bucket[1][i/sq][i%sq]);
        // cout << '\n';
        // rep(i, 0, N) cout << (char)('a'+bucket[2][i/sq][i%sq]);
        // cout << '\n';
        // cout << '\n';
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