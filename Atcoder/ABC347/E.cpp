#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, Q;
ll pfsum[200005];
vector<int> lst[200005];
bitset<200005> bs;

void solve(){
    cin >> N >> Q;
    ll cnt = 0LL;
    fill(pfsum, pfsum+N+1, 0LL);
    for(int i=1; i<=Q; i++){
        ll x;
        cin >> x;
        lst[x].push_back(i);
        if(bs[x]) cnt--;
        else cnt++;
        bs[x].flip();
        pfsum[i] = pfsum[i-1] + cnt;
    }
    pfsum[Q+1] = pfsum[Q] + cnt;
    for (int i=1; i<=N; i++){
        lst[i].push_back(Q+1);
        int j = 0;
        ll temp = 0;
        while(j+1 < lst[i].size()){
            int l = lst[i][j];
            int r = lst[i][j+1];
            temp += pfsum[r-1] - pfsum[l-1];
            j += 2;
        }
        cout << temp << " ";
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