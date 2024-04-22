#include <bits/stdc++.h>
using namespace std;

int arr[100001];
bool visited[100001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TC;
    cin >> TC;
    while(TC--){
        int N;
        cin >> N;
        for(int i=1; i<=N; i++){
            cin >> arr[i];
        }
        int ans=0;
        unordered_set<int> checked;
        for(int i = 1; i<=N; i++){
            if(checked.find(i) != checked.end()) continue;
            int cur = i, newstart;
            bool closed = false;
            fill(visited, visited+N, false);
            while(true){
                checked.insert(cur);
                if(visited[cur]){
                    closed = true;
                    newstart = cur;
                    break;
                }
                visited[cur] = true;
                cur = arr[cur];
            }
            if(closed){
                int newcur = newstart;
                while(true){
                    ans++;
                    newcur = arr[newcur];
                    if(newcur == newstart) break;
                }
            }
            cout << i << " " << ans << "\n";
        }
        cout << N << " " << ans << "\n";
        cout << N-ans << "\n";
    }
}