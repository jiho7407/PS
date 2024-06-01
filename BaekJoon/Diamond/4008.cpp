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

const ll mxN = 1e6;
ll N, a, b, c, x;
vector<pll> cvh; // 기울기, y절편
vector<ld> intersection;

ld getInter(pll a, pll b){
    return (ld)(b.second - a.second) / (a.first - b.first);
}

void solve(){
    // 입력
    cin >> N >> a >> b >> c;
    x = 0;

    // DP 계산, CHT를 이용하여 O(NlogN)
    cvh.push_back({0, 0});
    intersection.push_back(0);
    rep(i, 1, N+1){
        // 누적합 계산
        ll A; cin >> A; x += A;

        // 이번 P[i]가 들어갈 선분 찾기, DP 계산
        ll idx = lower_bound(intersection.begin(), intersection.end(), x) - intersection.begin();
        idx--;
        ll mx = cvh[idx].first * x + cvh[idx].second + a*x*x + b*x + c;
        if(i == N) cout << mx << '\n';

        // CHT 업데이트
        pll line = {-2*a*x, a*x*x - b*x + mx};
        while(1){
            ld newInter = getInter(cvh.back(), line);
            if(intersection.back() > newInter){
                cvh.pop_back();
                intersection.pop_back();
            }
            else{
                cvh.push_back(line);
                intersection.push_back(newInter);
                break;
            }
        }
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