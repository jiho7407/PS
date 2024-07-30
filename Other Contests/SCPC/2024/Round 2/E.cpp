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

struct UnionFind{
    int par[100000], cnt[100000];
    bool treasure[100000], Bwin[100000];
    int group;

    void init(int N){
        rep(i, 0, N){
            par[i] = i;
            cnt[i] = 1;
            treasure[i] = false;
            Bwin[i] = false;
        }
        group = N;
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(a > b) swap(a, b);
        par[b] = a;
        cnt[a] += cnt[b];
        treasure[a] |= treasure[b];
        Bwin[a] |= Bwin[b];
        group--;
    }
}UF;

int N, M;
vector<int> links[100000];
string S, T;

int win[100000]; // -1: 미방문, 0: 밥 승리, 1: 앨리스 승리
bool visited[100000];

void printAns(){
    rep(i, 0, N){
        if(win[i] == 0) cout << 'B';
        if(win[i] == 1) cout << 'A';
        if(win[i] == -1) cout << 'N';
    }
    cout << '\n';
}

void solve(){
    cin >> N >> M;
    cin >> S >> T;

    UF.init(N);
    rep(i, 0, N) links[i].clear();
    fill(win, win+N, -1);
    
    rep(i, 0, N) if(T[i] == 'T') UF.treasure[i] = true;
    rep(i, 0, M){
        int a, b; cin >> a >> b;
        a--; b--;
        links[a].push_back(b);
        links[b].push_back(a);
        if(S[a] == S[b]){
            UF.merge(a, b);
            if(S[a] == 'B' && T[a] == '.' && T[b] == '.') UF.Bwin[UF.find(a)] = true;
        }
    }

    rep(i, 0, N){ // 바로 판단할수있는경우
        int sz = UF.cnt[UF.find(i)];
        bool istrs = UF.treasure[UF.find(i)];
        if(S[i] == 'B' && UF.Bwin[UF.find(i)]) win[i] = 0; // 밥이 내부에서 돌아다님
        if(S[i] == 'A' && sz > 1 && istrs) win[i] = 1; // 앨리스가 내부에서 돌아다님
        if(S[i] == 'B' && sz == 1 && istrs) win[i] = 1; // 앨리스가 이 자리로 계속 보내면 이김
    }

    // 섭태 1
    bool flag1 = true;
    rep(i, 0, N) if(S[i] == 'B' && T[i] == '.') flag1 = false; // 모든 밥 땅은 보물이 있음
    if(flag1){
        rep(i, 0, N){
            if(S[i] == 'B') win[i] = 1;
        }
        rep(i, 0, N){
            if(win[i] != -1) continue;
            fill(visited, visited+N, false);
            vector<int> tmp;
            queue<int> q;
            q.push(i);
            tmp.push_back(i);
            visited[i] = true;
            bool flag = false; // 이길 수 있는 칸으로 갈 수 있나?
            while(!q.empty()){
                int cur = q.front(); q.pop();
                for(auto nxt: links[cur]){
                    if(visited[nxt]) continue;
                    visited[nxt] = true;
                    if(win[nxt] == 1) flag = true;
                    if(S[nxt] == 'A'){
                        q.push(nxt);
                        tmp.push_back(nxt);
                    }
                }
            }
            for(auto j: tmp) win[j] = flag;
        }
        printAns();
        return;
    }

    // 섭태 2
    bool flag2 = true;
    rep(i, 0, N) if(S[i] == 'A' && T[i] == '.') flag2 = false; // 모든 앨리스 땅은 보물이 있음
    if(flag2){
        rep(i, 0, N){
            if(win[i] != -1) continue;
            if(S[i] == 'B') continue;
            bool flag = false; // 앨리스가 지지 않는 땅이 있나?
            for(auto j: links[i]) if(win[j] != 0) flag = true;
            if(flag) win[i] = 1;
            else win[i] = 0;
        }
        // 앨리스 결정 완료
        rep(i, 0, N){
            if(win[i] != -1) continue;
            win[i] = 1; // 나머지는 앨리스 승리
        }
        printAns();
        return;
    }

    // 섭태 3
    bool flag3 = true;
    rep(i, 0, N) if(S[i] == 'B' && T[i] == 'T') flag3 = false; // 모든 밥 땅은 보물이 없음
    if(flag3){
        rep(i, 0, N){
            if(win[i] != -1) continue;
            if(S[i] == 'A') continue;
            bool flag = false; // 밥이 지지 않는 땅이 있나?
            for(auto j: links[i]){
                if(win[j] == 1) continue;
                if(T[j] == 'T') continue;
                flag = true;
            }
            if(flag) win[i] = 0;
            else win[i] = 1;
        }
        rep(i, 0, N){
            if(win[i] != -1) continue;
            fill(visited, visited+N, false);
            vector<int> tmp;
            queue<int> q;
            q.push(i);
            tmp.push_back(i);
            visited[i] = true;
            bool flag = false; // 이길 수 있는 칸으로 갈 수 있나?
            while(!q.empty()){
                int cur = q.front(); q.pop();
                for(auto nxt: links[cur]){
                    if(visited[nxt]) continue;
                    visited[nxt] = true;
                    if(win[nxt] == 1) flag = true;
                    if(S[nxt] == 'A'){
                        q.push(nxt);
                        tmp.push_back(nxt);
                    }
                }
            }
            for(auto j: tmp) win[j] = flag;
        }
        printAns();
        return;
    }

    // 섭태 4
    bool flag4 = true;
    rep(i, 0, N) if(S[i] == 'A' && T[i] == 'T') flag4 = false; // 모든 앨리스 땅은 보물이 없음
    if(flag4){
        // 가능 확정인 A 고르기
        rep(i, 0, N){
            if(win[i] != -1) continue;
            if(S[i] == 'B') continue;
            fill(visited, visited+N, false);
            bool flag = false; // 앨리스가 이길수 있는 땅이 있나?
            vector<int> tmp;
            queue<int> q;
            q.push(i);
            tmp.push_back(i);
            visited[i] = true;
            while(!q.empty()){
                int cur = q.front(); q.pop();
                for(auto nxt: links[cur]){
                    if(visited[nxt]) continue;
                    visited[nxt] = true;
                    if(win[nxt] == 1) flag = true;
                    if(S[nxt] == 'A'){
                        q.push(nxt);
                        tmp.push_back(nxt);
                    }
                }
            }
            if(flag) for(auto j: tmp) win[j] = 1;
        }

        // 불가능 확정인 A 고르기
        rep(i, 0, N){
            if(win[i] != -1) continue;
            if(S[i] == 'B') continue;
            fill(visited, visited+N, false);
            bool flag = false; // 갈수있는곳에 보물이 있는 B가 있나?
            vector<int> tmp;
            queue<int> q;
            q.push(i);
            tmp.push_back(i);
            visited[i] = true;
            while(!q.empty()){
                int cur = q.front(); q.pop();
                for(auto nxt: links[cur]){
                    if(visited[nxt]) continue;
                    visited[nxt] = true;
                    if(S[nxt] == 'B' && T[nxt] == 'T') flag = true;
                    if(S[nxt] == 'A'){
                        q.push(nxt);
                        tmp.push_back(nxt);
                    }
                }
            }
            if(flag) continue;
            for(auto j: tmp) win[j] = 0; // 어디로 가도 보물이 없음
        }

        // 불가능한 A로 보낼수있는 B 고르기
        rep(i, 0, N){
            if(win[i] != -1) continue;
            if(S[i] == 'A') continue;
            fill(visited, visited+N, false);
            bool flag = false; // 불가능한 A로 보낼수있나?
            vector<int> tmp;
            queue<int> q;
            q.push(i);
            tmp.push_back(i);
            visited[i] = true;
            while(!q.empty()){
                int cur = q.front(); q.pop();
                for(auto nxt: links[cur]){
                    if(visited[nxt]) continue;
                    visited[nxt] = true;
                    if(win[nxt] == 0) flag = true;
                    if(S[nxt] == 'B'){
                        q.push(nxt);
                        tmp.push_back(nxt);
                    }
                }
            }
            if(flag) for(auto j: tmp) win[j] = 0;
        }

        // 불가능한데로 못보내는 B는 다 가능
        rep(i, 0, N){
            if(win[i] == -1 && S[i] == 'B') win[i] = 1;
        }
        
        // 가능한 A 고르기
        rep(i, 0, N){
            if(win[i] != -1) continue;
            fill(visited, visited+N, false);
            vector<int> tmp;
            queue<int> q;
            q.push(i);
            tmp.push_back(i);
            visited[i] = true;
            bool flag = false; // 이길 수 있는 칸으로 갈 수 있나?
            while(!q.empty()){
                int cur = q.front(); q.pop();
                for(auto nxt: links[cur]){
                    if(visited[nxt]) continue;
                    visited[nxt] = true;
                    if(win[nxt] == 1) flag = true;
                    if(S[nxt] == 'A'){
                        q.push(nxt);
                        tmp.push_back(nxt);
                    }
                }
            }
            for(auto j: tmp) win[j] = flag;
        }

        printAns();
        return;
    }

    printAns();
    return;
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