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

ll N;
ll A[100000];

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    reverse(A, A+N);

    priority_queue<ll> pq;
    ll sum = 0;
    ld mx = 0;

    vector<ll> ans;

    rep(i, 0, N){
        sum += A[i];
        pq.push(-A[i]);
        if(i == 0) continue;

        ld tmp = (ld)(sum + pq.top()) / i;
        if(abs(tmp - mx) < 1e-9){
            ans.push_back(N-i-1);
        }
        else if(tmp > mx){
            mx = tmp;
            ans.clear();
            ans.push_back(N-i-1);
        }
    }

    sort(ans.begin(), ans.end());
    for(auto x: ans){
        if(x == 0) continue;
        if(x >= N-1) continue;
        cout << x << '\n';
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