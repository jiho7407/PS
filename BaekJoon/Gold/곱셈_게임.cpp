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

vector<int> usable;
vector<int> DP(1000001);

void make_usable(int idx, int cur, vector<int>& nums){
    if(idx > 6) return;
    if(cur) usable.push_back(cur);
    for(auto num: nums){
        make_usable(idx+1, cur*10 + num, nums);
    }
}

int calc(vector<int>& nums, int K){
    if(K == 1) return 0;
    if(DP[K] != 1e9) return DP[K];
    int &ret = DP[K];
    for(auto num: usable){
        if(num <= 1) continue;
        if(num > K) break;
        if(K%num != 0) continue;
        ret = min(ret, calc(nums, K/num) + 1);
    }
    return ret;
}

void solve(){
    int N; cin >> N;
    vector<int> nums(N);
    rep(i, 0, N) cin >> nums[i];

    usable.clear();
    make_usable(0, 0, nums);
    sort(usable.begin(), usable.end());
    usable.erase(unique(usable.begin(), usable.end()), usable.end());
    
    int M; cin >> M;
    while(M--){
        int K; cin >> K;
        rep(i, 0, K+1) DP[i] = 1e9;
        int ans = calc(nums, K);
        cout << (ans == 1e9 ? -1 : ans-1) << '\n';
    }
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}