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

int N;
vector<pll> balloons;
ll DP[5001][5001];

bool cmp(pll a, pll b){
    return a.first + a.second < b.first + b.second;
}

void solve(){
    cin >> N;
    rep(i, 0, N){
        ll L, D; cin >> L >> D;
        balloons.push_back({L, D});
    }
    sort(balloons.begin(), balloons.end(), cmp);

    ll H = 0;
    priority_queue<ll> PQ;
    for(auto [L, D]: balloons){
        if(H <= L){
            H += D;
            PQ.push(D);
        }else{
            if(D < PQ.top() && H - PQ.top() <= L){
                H -= PQ.top(); PQ.pop();
                H += D;
                PQ.push(D);
            }
        }
    }
    cout << PQ.size();
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