#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
vector<int> links[300000];

int getDist(int cur, int goal, int par){
    if(cur == goal) return 0;
    for(auto i: links[cur]){
        if(i == par) continue;
        return getDist(i, goal, cur) + 1;
    }
}

ll comb(ll a){
    // cout << a << "C2 " << a*(a-1)/2 << '\n';
    return a*(a-1)/2;
}

void solve(){
    cin >> N;
    rep(i, 0, N+1){
        int a, b; cin >> a >> b;
        a--; b--;
        links[a].push_back(b);
        links[b].push_back(a);
    }

    // 추가로 이어진 쌍 찾기
    ll a = -1, b = -1;
    rep(i, 0, N){
        if(links[i].size() != 3) continue;
        if(a == -1) a = i;
        else b = i;
    }

    // 추가로 이어진 간선 제거
    rep(i, 0, 3){
        if(links[a][i] == b){
            links[a].erase(links[a].begin() + i);
            break;
        }
    }
    rep(i, 0, 3){
        if(links[b][i] == a){
            links[b].erase(links[b].begin() + i);
            break;
        }
    }

    // 경우의수 계산
    int dist = getDist(a, b, -1);
    ll ans = 0;
    ans += comb(dist);
    ans += comb(N-dist);
    // cout << a << ' ' << b << ' ' << dist << '\n';
    cout << ans << '\n';

    // 초기화
    rep(i, 0, N) links[i].clear();
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        cout << "Case #" << TC << '\n';
        solve();
    }
    return 0;
}