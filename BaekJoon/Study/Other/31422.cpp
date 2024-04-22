#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

long long N, lst[200010];
long long AND, OR, XOR;
long long tempAND, tempOR, tempXOR;
long long mod = 998244353;

int main(){
    cin >> N;
    for(long long i = 0; i<N; i++){
        cin >> lst[i];
    }
    AND=0, OR=0, XOR=0;
    long long D = 1;
    for(long long d = 1; d<=30; d++){
        // AND
        long long cnt1 = 0;
        tempAND = 0;
        for(long long i = 0; i<N; i++){
            if(lst[i]%2) cnt1++;
            else{
                tempAND += cnt1 * (cnt1+1) / 2;
                cnt1 = 0;
            }
        }
        tempAND += cnt1 * (cnt1+1) / 2;
        tempAND %= mod;
        AND += tempAND*D%mod;
        AND %= mod;

        // OR
        long long cnt0 = 0;
        tempOR = N*(N+1)/2;
        for(long long i = 0; i<N; i++){
            if(lst[i]%2){
                tempOR -= cnt0 * (cnt0+1)/2;
                cnt0 = 0;
            }
            else cnt0++;
        }
        tempOR -= cnt0 * (cnt0+1)/2;
        tempOR %= mod;
        OR += tempOR*D%mod;
        OR %= mod;

        // XOR
        long long pfsum = 0;
        long long odd = 0, even = 1;
        tempXOR = 0;
        for(long long i = 0; i<N; i++){
            if(lst[i]%2){
                pfsum += 1;
            }
            if(pfsum%2){
                tempXOR += even;
                odd++;
            }
            else{
                tempXOR += odd;
                even++;
            }
        }
        tempXOR %= mod;
        XOR += tempXOR*D%mod;
        XOR %= mod;



        for(long long i = 0; i<N; i++){
            lst[i]/=2;
        }
        D = D*2%mod;
    }
    cout << AND << " " << OR << " " << XOR;
}