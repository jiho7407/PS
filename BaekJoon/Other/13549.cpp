#include <bits/stdc++.h>
using namespace std;

deque<pair<int, int>> dq;
int dist[100001];

int main(void){
    int N, K, cur, curdist;
    cin >> N >> K;

    dq.push_back({N, 0});

    fill(dist, dist+100001, -1);
    dist[N] = 0;
    
    while(!dq.empty()) {
        auto cur = dq.front(); dq.pop_front();
        if(cur.first > 0 and (dist[cur.first-1] == -1 || dist[cur.first-1] > dist[cur.first] + 1)){
            dq.push_back({cur.first-1, cur.second+1});
            dist[cur.first-1] = cur.second+1;
        }
        if(cur.first < 100000 and (dist[cur.first+1] == -1 || dist[cur.first+1] > dist[cur.first] + 1)){
            dq.push_back({cur.first+1, cur.second+1});
            dist[cur.first+1] = cur.second+1;
        }
        if(cur.first == 0) continue; 
        if(cur.first < 50001 and (dist[cur.first*2] == -1 || dist[cur.first*2] > dist[cur.first])){
            dq.push_front({cur.first*2, cur.second});
            dist[cur.first*2] = cur.second;
        }
    }
    cout << dist[K];
}