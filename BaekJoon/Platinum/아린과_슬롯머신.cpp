#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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

void solve(){
    int N, M; cin >> N >> M;
    vector<int> v(N);
    rep(i, 0, N) cin >> v[i];

    rep(i, 0, N){
        if((v[i] % 7 != 0) || (v[i] % 49 == 0)){
            cout << -1;
            return;
        }
        v[i] /= 7;
    }

    vector<int> primes;
    vector<bool> isPrime(1200, true);
    isPrime[0] = isPrime[1] = false;
    rep(i, 2, 1200) if(isPrime[i]){
        primes.push_back(i);
        for(int j = i*i; j < 1200; j+=i) isPrime[j] = false;
    }
    int sz = primes.size();

    int ans = 0;

    vector<int> pCnt(sz);
    set<int> st;
    deque<pii> dq;
    rep(i, 0, N){
        while(!dq.empty() && dq.front().first <= i){
            auto [idx, pidx] = dq.front(); dq.pop_front();
            if(pidx > sz) st.erase(pidx);
            else pCnt[pidx]--;
        }
        
        rep(pidx, 0, sz){
            if(v[i] == 1) break;
            int P = primes[pidx];

            for(int j = pCnt[pidx]; j && v[i] % P == 0; j--){
                v[i] /= P;
            }

            while(v[i] % P == 0){
                v[i] /= P;
                pCnt[pidx]++;
                dq.push_back({i+M, pidx});
                ans++;
            }
        }
        if(st.find(v[i]) != st.end()) continue;
        if(v[i] != 1){
            st.insert(v[i]);
            dq.push_back({i+M, v[i]});
            ans++;
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