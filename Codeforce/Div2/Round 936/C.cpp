#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int comp;
vector<vector<int>> links;

int dfs(int a, int par, int size) {
    int curdeg = 1;
    for (int g : links[a]) {
        if (g == par) continue;
        int result = dfs(g, a, size);
        if (result >= size) {
            comp++;
        } else {
            curdeg += result;
        }
    }
    return curdeg;
}


int main(){
    fastio();int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        links.assign(N, vector<int>());

        for (int i = 0; i < N - 1; ++i) {
            int s, e;
            cin >> s >> e;
            --s; --e;
            links[s].emplace_back(e);
            links[e].emplace_back(s);
        }

        int left = 1, right = N, ans = 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            comp = 0;
            int result = dfs(0, -1, mid);
            if (result >= mid) {
                comp++;
            }
            if (comp > K) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}