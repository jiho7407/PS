#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
int V[500000];
bool used[500000];

bool cmp(int a, int b){
    return a > b;
}

void solve(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> V[i];
    }
    sort(V, V+N, cmp);
    int ans = N;
    int l = 0, r = N/2;
    while(l < N/2){
        while(r < N && (used[r] || V[l] < 2*V[r])){
            r++;
        }
        if(r == N){
            break;
        }
        l++;
        r++;
        ans--;
    }
    cout << ans;
    return;
}

int main(){
    fastio();
    int tc = 1;
    while(tc--){
        solve();
    }
    return 0;
}