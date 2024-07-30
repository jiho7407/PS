#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct UF{ // 0-based
    vector<int> par, cnt;

    void init(int N){
        par.resize(N);
        cnt.resize(N, 1);
        rep(i, 0, N) par[i] = i;
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(x > y) swap(x, y);
        par[y] = x;
        cnt[x] += cnt[y];
    }
}uf;

int N, Q;
vector<tuple<int, bool, int>> Xs, Ys; // val, isend, idx;

void solve(){
    cin >> N >> Q;
    rep(i, 0, N){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        Xs.push_back({x1, 0, i});
        Xs.push_back({x2, 1, i});
        Ys.push_back({y1, 0, i});
        Ys.push_back({y2, 1, i});
    }

    sort(Xs.begin(), Xs.end());
    sort(Ys.begin(), Ys.end());
    uf.init(N);

    int head = -1, cnt = 0;
    for(auto [val, isEnd, idx] : Xs){
        if(isEnd) cnt--;
        else{
            if(cnt == 0) head = idx;
            else uf.merge(head, idx);
            cnt++;
        }
    }

    for(auto [val, isEnd, idx] : Ys){
        if(isEnd) cnt--;
        else{
            if(cnt == 0) head = idx;
            uf.merge(head, idx);
            cnt++;
        }
    }

    while(Q--){
        int a, b; cin >> a >> b;
        a--; b--;
        cout << (uf.find(a) == uf.find(b) ? 1 : 0) << '\n';
    }
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