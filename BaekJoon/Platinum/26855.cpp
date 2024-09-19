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
    int mxsz;

    void init(int N){
        par.resize(N);
        cnt.resize(N);
        rep(i, 0, N){
            par[i] = i;
            cnt[i] = 1;
        }
        group = N;
        mxsz = 1;
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(a > b) swap(a, b);
        par[b] = a;
        cnt[a] += cnt[b];
        cnt[b] = 0;
        group--;
        mxsz = max(mxsz, cnt[a]);
    }
}UF;

bool isPrime[1000001];
vector<int> primes;

int N;
int A[100000];
vector<pii> edges;
vector<pii> nedges[1000001];

void solve(){
    fill(isPrime, isPrime+1000001, true);
    isPrime[0] = isPrime[1] = false;
    rep(i, 2, 1000001){
        if(!isPrime[i]) continue;
        primes.push_back(i);
        for(int j = i*2; j < 1000001; j+=i){
            isPrime[j] = false;
        }
    }

    cin >> N;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N-1){
        int a, b; cin >> a >> b;
        a--; b--;
        edges.push_back({a, b});
    }

    // 모두 1인지 검사
    bool all1 = true;
    rep(i, 0, N) if(A[i] != 1) all1 = false;
    if(all1){
        cout << 0;
        return;
    }

    for(auto [a, b]: edges){
        int G = __gcd(A[a], A[b]);
        for(int p: primes){
            if(p*p > G){
                break;
            }
            if(G%p == 0){
                nedges[p].push_back({a, b});
                while(G%p == 0) G /= p;
            }
        }
        if(G > 1) nedges[G].push_back({a, b});
    }

    int ans = 1;
    UF.init(N);
    rep(p, 2, 1000001){
        if(!isPrime[p]) continue;
        if(nedges[p].empty()) continue;
        for(auto [a, b]: nedges[p]){
            UF.merge(a, b);
        }
        ans = max(ans, UF.mxsz);
        for(auto [a, b]: nedges[p]){
            UF.cnt[a] = UF.cnt[b] = 1;
            UF.par[a] = a;
            UF.par[b] = b;
        }
    }
    cout << ans;
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