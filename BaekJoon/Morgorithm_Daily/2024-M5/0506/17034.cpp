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

int N, D[100000], root[100001];
vector<int> dish[100001];

void solve(){
    cin >> N;
    fill(root, root+N, 0);
    rep(i, 0, N) cin >> D[i];
    int complete = 0;
    rep(i, 0, N){
        int d = D[i];
        if(d<complete){cout << i; return;}
        int j = d;
        while(j>0 && root[j] == 0){
            root[j] = d;
            j--;
        }
        while(!dish[root[d]].empty() && dish[root[d]].back() < d){
            complete = dish[root[d]].back(); dish[root[d]].pop_back();
        }
        dish[root[d]].push_back(d);
    }
    cout << N;
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