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

ll N, K, M;
pll cows[50000];
bool used[50000];
priority_queue<ll, vector<ll>, greater<ll>> pq;
priority_queue<ll> pq2;

bool cmp(pll a, pll b){
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

bool cmp2(pll a, pll b){
    return a.first < b.first;
}

void solve(){
    cin >> N >> K >> M;
    rep(i, 0, N) cin >> cows[i].first >> cows[i].second;
    sort(cows, cows+N, cmp);

    if(M < cows[0].second){
        cout << 0 << '\n';
        return;
    }

    ll cnt = 0;

    rep(i, 0, K){
        auto [p, c] = cows[i];
        if(c <= M){
            pq.push(p-c);
            cnt++;
            M -= c;
        }
    }
    rep(i, K, N){
        auto [p, c] = cows[i];
        ll coup = c + pq.top();
        ll nocoup = p;
        if(min(coup, nocoup) <= M){
            cnt++;
            M -= min(coup, nocoup);
            if(coup < nocoup){
                pq.pop();
                pq.push(p-c);
            }
            else pq2.push(p);
        }
        else{
            if(!pq2.empty() && p < pq2.top()){
                M += pq2.top() - p;
                pq2.pop();
                pq2.push(p);
            }
        }
        // cout << p << ' ' << c << ' ' << M << ' ' << cnt << '\n';
    }

    cout << cnt << '\n';
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