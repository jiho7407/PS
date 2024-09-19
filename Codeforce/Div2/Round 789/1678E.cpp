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
    int par[100000], cnt[100000];
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

    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(a > b) swap(a, b);
        par[b] = a;
        cnt[a] += cnt[b];
        cnt[b] = 0;
        group--;
    }
}UF;

ll f(ll n, ll k){
    if(k == 0) return 0;
    if(k%2) return f(n, k-1);
    ll ret = 0;
    rep(i, 1, k) ret += (n-i);
    ret += (n-k/2);
    // cout << n << ' ' << k << ' ' << ret << '\n';
    return ret;
}

ll N;
ll A[100000];
map<ll, ll> mp;

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N){
        ll x; cin >> x;
        mp[x] = i;
    }

    UF.init(N);
    rep(i, 0, N){
        if(UF.find(i) != i) continue;
        ll cur = i;
        while(1){
            ll nxt = mp[A[cur]];
            if(UF.find(nxt) == UF.find(cur)) break;
            UF.merge(cur, nxt);
            cur = nxt;
        }
    }

    vector<ll> szs;
    rep(i, 0, N){
        if(UF.find(i) == i) szs.push_back(UF.cnt[i]);
    }
    sort(szs.begin(), szs.end(), greater<ll>());

    ll ans = 0;
    for(auto sz: szs){
        ans += f(N, sz);
        N -= sz;
        if(sz%2) N++;
    }
    cout << ans << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}