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

// 유파
// 분리집합
struct UnionFind{
    int par[1000], cnt[1000];
    int group;

    void init(int N){
        rep(i, 0, N){
            par[i] = i;
            cnt[i] = 1;
        }
        group = N;
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    bool merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(a > b) swap(a, b);
        par[b] = a;
        cnt[a] += cnt[b];
        cnt[b] = 0;
        group--;
        return true;
    }
}UF;

int N, M, K;
vector<pii> links;
bool killed[10000];

void solve(){
    cin >> N >> M >> K;
    rep(i, 0, M){
        int x, y; cin >> x >> y;
        x--; y--;
        links.push_back({x, y});
    }

    bool flag = false; // 불가능 여부
    rep(i, 0, K){
        if(flag){
            cout << 0 << ' ';
            continue;
        }
        int ret = 0;
        UF.init(N);
        bool flag2 = false; // 첫 간선 여부
        rep(i, 0, M){
            if(killed[i]) continue;
            if(!flag2){
                flag2 = true;
                killed[i] = true;
            }
            auto [x, y] = links[i];
            if(UF.merge(x, y)) ret += (i+1);
        }
        if(UF.group > 1){
            flag = true;
            cout << 0 << ' ';
            continue;
        }
        else cout << ret << ' ';
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