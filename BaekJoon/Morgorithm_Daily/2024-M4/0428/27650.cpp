#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxN = 5000001;
vector<int> primes;

void calc(int N){
    N++;
    vector<bool> isPrime(N, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < N; i++){
        if(!isPrime[i]) continue;
        primes.push_back(i);
        for(int j = i*2; j < N; j += i){
            isPrime[j] = false;
        }
    }
    return;
}

void solve(){
    int N; cin >> N;
    calc(N);
    int ok = -1, ng = primes.size()-1;
    while(ng - ok > 1){
        int mid = (ok + ng) / 2;
        cout << "? " << primes[mid] << '\n';
        cout.flush();
        int res; cin >> res;
        if(res == 1) ok = mid;
        else ng = mid;
    }
    cout << "! " << primes[ng] << '\n';
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}