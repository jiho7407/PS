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

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
const int mxN = 1e6;
int N, M;
string board[mxN];
int sz[mxN]; // 각 그룹의 크기
vector<int> RN[mxN], CN[mxN]; // 각 행에서 만날수있는 그룹
int Rcnt[mxN], Ccnt[mxN]; // 각 행/열 . 개수
bool visited[mxN];

void solve(){
    // 입력받기
    cin >> N >> M;
    rep(i, 0, N) cin >> board[i];

    // 초기화작업
    int bfsn = 0;
    fill(sz, sz+N, 0);
    rep(i, 0, N) RN[i].clear(), Rcnt[i] = 0;
    rep(i, 0, M) CN[i].clear(), Ccnt[i] = 0;
    fill(visited, visited+N*M, false);

    // bfs로 그룹 나누기
    rep(i, 0, N) rep(j, 0, M){
        if(board[i][j] == '.'){ Rcnt[i]++; Ccnt[j]++; continue; }
        if(visited[i*M+j]) continue;
        queue<pii> q; q.push({i, j});
        visited[i*M+j] = true;
        int cnt = 1;
        RN[i].push_back(bfsn);
        CN[j].push_back(bfsn);
        while(!q.empty()){
            auto [r, c] = q.front(); q.pop();
            rep(d, 0, 4){
                int nr = r+dx[d], nc = c+dy[d];
                if(nr<0||nr>=N||nc<0||nc>=M) continue;
                if(board[nr][nc] == '.') continue;
                if(visited[nr*M+nc]) continue;
                visited[nr*M+nc] = true;
                cnt++;
                q.push({nr, nc});
                RN[nr].push_back(bfsn);
                CN[nc].push_back(bfsn);
            }
        }
        sz[bfsn++] = cnt;
    }

    // 중복제거
    rep(i, 0, N){
        sort(RN[i].begin(), RN[i].end());
        RN[i].erase(unique(RN[i].begin(), RN[i].end()), RN[i].end());
    }
    rep(i, 0, M){
        sort(CN[i].begin(), CN[i].end());   
        CN[i].erase(unique(CN[i].begin(), CN[i].end()), CN[i].end());
    }

    int ans = 0;
    // 행 순환
    rep(i, 0, N){
        int cnt = Rcnt[i];
        vector<int> possible;
        if(i-1 >= 0) for(auto r : RN[i-1]) possible.push_back(r);
        for(auto r : RN[i]) possible.push_back(r);
        if(i+1 < N) for(auto r : RN[i+1]) possible.push_back(r);
        sort(possible.begin(), possible.end());
        possible.erase(unique(possible.begin(), possible.end()), possible.end());
        for(auto r: possible) cnt += sz[r];
        // cout << i << ' ' << cnt << '\n';
        ans = max(ans, cnt);
    }

    // 열 순환
    rep(i, 0, M){
        int cnt = Ccnt[i];
        vector<int> possible;
        if(i-1 >= 0) for(auto r : CN[i-1]) possible.push_back(r);
        for(auto r : CN[i]) possible.push_back(r);
        if(i+1 < M) for(auto r : CN[i+1]) possible.push_back(r);
        sort(possible.begin(), possible.end());
        possible.erase(unique(possible.begin(), possible.end()), possible.end());
        for(auto r: possible) cnt += sz[r];
        // cout << i << ' ' << cnt << '\n';
        ans = max(ans, cnt);
    }

    cout << ans << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}