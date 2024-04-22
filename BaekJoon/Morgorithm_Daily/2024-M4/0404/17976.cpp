#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N;
pair<ll, ll> S[100010];

bool test(ll mid){
    ll last = S[0].first-mid;
    for(int i=0; i<N; i++){
        if(last + mid < S[i].first){
            last = S[i].first;
        }
        else if(last+mid <= S[i].first + S[i].second){
            last += mid;
        }
        else return false;
    }
    return true;
}

void solve(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> S[i].first >> S[i].second;
    }
    sort(S, S+N);
    ll left = 0, right = ll(1e10);
    while(left < right){
        ll mid = (left + right) / 2;
        bool res = test(mid);
        if(res) left = mid + 1;
        else right = mid;
    }
    cout << left-1 << '\n';
    return;
}

int main(){
    fastio();
    solve();
    return 0;
}