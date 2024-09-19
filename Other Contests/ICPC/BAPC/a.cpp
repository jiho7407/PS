#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll N,M,K; cin>>N>>M>>K;
    vector<ll> A(N);
    for (int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(A.rbegin(), A.rend());
    ll t = M+K;
    t = min(t,N);
    ll sum = 0;
    ll x= 0;
    for (int i=0;i<N;i++){
        sum+=A[i];
        if (i<t){x+=A[i];}
    }

    cout<<fixed<<setprecision(10)<<(double)x/sum*100;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}