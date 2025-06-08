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

ll pow(ll a, ll b, ll mod){
    ll ret = 1;
    while(b){
        if(b&1) ret = (ret*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return ret;
}

ll inv(ll a, ll mod){
    return pow(a, mod-2, mod);
}

vector<bool> calc(ll n, vector<ll> &a);

vector<bool> calc_prime(ll n, vector<ll> &a){
    vector<ll> idxs;
    vector<bool> ret(2*n-1, false);
    rep(i, 0, 2*n-1) idxs.push_back(i);
    sort(idxs.begin(), idxs.end(), [&](ll p, ll q){
        return (a[p]%n) < (a[q]%n);
    });

    // 같은 숫자가 N개 이상이면 그 합은 N의 배수
    rep(i, 0, n){
        if((a[idxs[i]]%n) != (a[idxs[i+n-1]]%n)) continue;
        rep(j, 0, n) ret[idxs[i+j]] = true;
        return ret;
    }

    // 아니라면 역추적으로 찾아오자
    ll s = 0;
    rep(i, 0, n) s += a[idxs[i]], s %= n;
    vector<bool> T(n, false); // 나머지 집합
    vector<ll> from(n, 0); // 역추적용, 해당 나머지가 언제 추가되었는지

    T[s] = true;
    rep(i, 0, n){
        if(T[0]) break;
        ll d = (a[idxs[i+n]] - a[idxs[i]]) % n;
        if(d<0) d += n;
        ll ng = s*inv(d, n) % n, ok = n;
        while(ok - ng > 1){
            ll mid = (ok + ng) / 2;
            if(!T[mid*d % n]) ok = mid;
            else ng = mid;
        }
        ok = ok*d % n;

        T[ok] = true;
        from[ok] = i;
    }

    ll cur = 0; // 현재 나머지
    rep(i, 0, n) ret[idxs[i]] = true;
    while(cur != s){ // 시작으로 갈때까지 역추적
        ll idx = from[cur];
        swap(ret[idxs[idx]], ret[idxs[idx+n]]);
        ll d = (a[idxs[idx+n]] - a[idxs[idx]]) % n;
        cur = (cur - d + n) % n;
    }

    return ret;
}

vector<bool> calc_comp(ll n, ll m, vector<ll> &a){
    vector<vector<ll>> rets;
    vector<ll> idxs;
    rep(i, 0, n-1) idxs.push_back(i);

    // n개를 골라서 n의 배수인걸 2m-1개 만들기
    rep(i, 0, 2*m-1){
        rep(j, 0, n) idxs.push_back((i+1)*n + j - 1);
        vector<ll> _arr;
        for(auto idx: idxs) _arr.push_back(a[idx]);
        vector<bool> tmp = calc(n, _arr);

        vector<ll> used, unused;
        rep(j, 0, 2*n-1){
            if(tmp[j]) used.push_back(idxs[j]);
            else unused.push_back(idxs[j]);
        }
        
        idxs = unused;
        rets.push_back(used);
    }

    // n으로 나누어 떨어지는 수 2m-1개에서 m개 골라 m의 배수 만들기
    vector<ll> new_arr;
    rep(i, 0, 2*m-1){
        ll ret = 0;
        rep(j, 0, n) ret += a[rets[i][j]];
        new_arr.push_back((ret/n)%m);
    }
    vector<bool> tmp = calc(m, new_arr);
    vector<bool> ret(2*n*m-1, false);

    rep(i, 0, 2*m-1) if(tmp[i]){
        for(auto idx: rets[i]){
            ret[idx] = true;
        }
    }

    return ret;
}

vector<bool> calc(ll n, vector<ll> &a){
    if(n == 1) return vector<bool>(1, true);
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0) return calc_comp(i, n/i, a);
    }
    return calc_prime(n, a);
}

void solve(){
    ll N; cin >> N;
    vector<ll> A(2*N-1);
    rep(i, 0, 2*N-1) cin >> A[i];
    vector<bool> ans = calc(N, A);
    rep(i, 0, 2*N-1) if(ans[i]) cout << A[i] << " ";
    
    // cout << "\n";
    // ll ret = 0;
    // rep(i, 0, 2*N-1) if(ans[i]) ret += A[i];
    // cout << ret << "\n";
    // cout << ret%N << "\n";
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