#include <bits/stdc++.h>
using namespace std;

deque<pair<int, int>> dq;
bool visited[100001] = {false};

int main(void){
    int N, K, cur, dist;
    cin >> N >> K;

    dq.push_back({N, 0});

    fill(visited, visited+100001, false);
    visited[N] = true;

    while(true){
        pair<int, int> cur = dq.front(); dq.pop_front();
        if(cur.first == K){
            cout << cur.second;
            break;
        }
        if(cur.first > 0 && !visited[cur.first-1]){
            visited[cur.first-1] = true;
            dq.push_back({cur.first-1, cur.second+1});
        }
        if(cur.first < 100000 && !visited[cur.first+1]){
            visited[cur.first+1] = true;
            dq.push_back({cur.first+1, cur.second+1});
        }
        if(cur.first < 50001 && !visited[cur.first*2]){
            visited[cur.first*2] = true;
            dq.push_back({cur.first*2, cur.second+1});
        }
    }
}