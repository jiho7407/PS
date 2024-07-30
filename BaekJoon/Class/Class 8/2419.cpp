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

int N, M;
vector<int> candy;
int DPL[301][301], DPR[301][301];

int dfs(int start, int end, int remain, int isRight){
    if(remain == 0) return (isRight ? DPR[start][end] : DPL[start][end]);

    int ret = 1e8;

    // 왼쪽으로 가기
    if(start > 0){
        int nxt = start - 1;
        if(isRight){
            int cost = candy[end] - candy[nxt];
            cost *= remain;
            if(DPL[nxt][end] > DPR[start][end] + cost){
                DPL[nxt][end] = DPR[start][end] + cost;
                ret = min(ret, dfs(nxt, end, remain-1, 0));
            }
        }
        else{
            int cost = candy[start] - candy[nxt];
            cost *= remain;
            if(DPL[nxt][end] > DPL[start][end] + cost){
                DPL[nxt][end] = DPL[start][end] + cost;
                ret = min(ret, dfs(nxt, end, remain-1, 0));
            }
        }
    }

    // 오른쪽으로 가기
    if(end < N){
        int nxt = end + 1;
        if(isRight){
            int cost = candy[nxt] - candy[end];
            cost *= remain;
            if(DPR[start][nxt] > DPR[start][end] + cost){
                DPR[start][nxt] = DPR[start][end] + cost;
                ret = min(ret, dfs(start, nxt, remain-1, 1));
            }
        }
        else{
            int cost = candy[nxt] - candy[start];
            cost *= remain;
            if(DPR[start][nxt] > DPL[start][end] + cost){
                DPR[start][nxt] = DPL[start][end] + cost;
                ret = min(ret, dfs(start, nxt, remain-1, 1));
            }
        }
    }
    return ret;
}

void solve(){
    cin >> N >> M;
    candy.push_back(0);
    rep(i, 0, N){
        int a; cin >> a;
        candy.push_back(a);
    }
    sort(candy.begin(), candy.end());

    int start = lower_bound(candy.begin(), candy.end(), 0) - candy.begin();
    int ans = 0;
    rep(i, 1, N+1){
        fill_n(&DPL[0][0], 301*301, 1e8);
        fill_n(&DPR[0][0], 301*301, 1e8);
        DPL[start][start] = DPR[start][start] = 0;
        ans = max(ans, M*i - dfs(start, start, i, 0));
    }
    cout << ans;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}