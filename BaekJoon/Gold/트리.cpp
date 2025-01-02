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

struct UnionFind{
    vector<int> par, cnt;
    int group;
    vector<bool> isTree;

    void init(int N){
        par.resize(N);
        cnt.resize(N);
        isTree.resize(N);
        rep(i, 0, N){
            par[i] = i;
            cnt[i] = 1;
            isTree[i] = 1;
        }
        group = N;
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b){
            isTree[a] = 0;
            return;
        }
        if(a > b) swap(a, b);
        par[b] = a;
        cnt[a] += cnt[b];
        cnt[b] = 0;
        isTree[a] = isTree[a] && isTree[b];
        group--;
    }
}UF;

void solve(){
    int idx = 1;
    while(1){
        int N, M; cin >> N >> M;
        if(N == 0 && M == 0) return;
        UF.init(N);
        vector<bool> isTree(N, 1);
        rep(i, 0, M){
            int a, b; cin >> a >> b;
            a--; b--;
            UF.merge(a, b);
        }

        int ans = 0;
        rep(i, 0, N) if(UF.find(i) == i && UF.isTree[i]) ans++;

        cout << "Case " << idx++ << ": ";
        if(ans == 0) cout << "No trees.\n";
        else if(ans == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << ans << " trees.\n";
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