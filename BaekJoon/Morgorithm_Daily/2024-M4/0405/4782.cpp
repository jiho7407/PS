#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll B, N;
vector<pair<ll, ll>> ans;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.first*b.second == a.second*b.first) return a.first < b.first;
    return a.first*b.second < a.second*b.first;
}

void solve(){
    while(1){
        cin >> B >> N;
        if(B == 0 && N == 0) break;
        ans.clear();
        ans.push_back({0, 2*N});
        ll GCD = gcd(B, N);
        for(ll A = 1; A<B; A++){
            ll sqr = sqrt(B*B - A*B);
            if(sqr*sqr != B*B - A*B) continue;
            if(sqr % (B/GCD)) continue;
            ans.push_back({A, N+sqr*N/B});
            ans.push_back({A, N-sqr*N/B});
        }
        sort(ans.begin(), ans.end(), cmp);
        for(auto a : ans){
            cout << a.first << "/" << a.second << " ";
        }
        cout << "\n";
    }
    return;
}

int main(){
    fastio();
    solve();
    return 0;
}