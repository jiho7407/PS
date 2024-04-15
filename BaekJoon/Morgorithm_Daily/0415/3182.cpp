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
int nxt[1001];
bool visited[1001];

void solve(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> nxt[i];
    }
    int ans = 0;
    int mx = 0;
    for(int i = 1; i <= N; i++){
        fill(visited, visited + N + 1, false);
        int cnt = 0;
        for(int j = i; !visited[j]; j = nxt[j]){
            visited[j] = true;
            cnt++;
        }
        if(cnt > mx){
            mx = cnt;
            ans = i;
        }
    }
    cout << ans;
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