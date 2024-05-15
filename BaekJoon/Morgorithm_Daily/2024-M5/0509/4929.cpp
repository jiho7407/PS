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

int N, M;

void solve(){
    while(1){
        cin >> N;
        if(N == 0) break;
        vector<int> NV;
        rep(i, 0, N){
            int a;
            cin >> a;
            NV.push_back(a);
        }
        cin >> M;
        vector<int> MV, cross;
        rep(i, 0, M){
            int a;
            cin >> a;
            MV.push_back(a);
            if(find(NV.begin(), NV.end(), a) != NV.end()){
                cross.push_back(a);
            }
        }
        int ans = 0;
        int n = 0, m = 0;
        int tempN=0, tempM=0;
        rep(i, 0, cross.size()){
            while(NV[n] < cross[i]){
                tempN += NV[n];
                n++;
            }
            while(MV[m] < cross[i]){
                tempM += MV[m];
                m++;
            }
            ans += max(tempN, tempM);
            tempN = 0, tempM = 0;
        }
        while(n < N){
            tempN += NV[n];
            n++;
        }
        while(m < M){
            tempM += MV[m];
            m++;
        }
        ans += max(tempN, tempM);
        cout << ans << "\n";
    }
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