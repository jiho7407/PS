#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    cin.ignore(); // 입력 버퍼 비우기

    string S, T;
    getline(cin, S);
    getline(cin, T);

    vector<vector<int>> dpI(N+1, vector<int>(M+1, 0)), dpO(N+1, vector<int>(M+1, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (S[i] == 'I') {
                dpI[i+1][j+1] = dpO[i][j+1] + 1;
            } else {
                if (dpI[i][j+1] == 0) continue;
                dpO[i+1][j+1] = dpI[i][j+1] + 1;
            }
            if (T[j] == 'I') {
                dpI[i+1][j+1] = max(dpI[i+1][j+1], dpO[i+1][j] + 1);
            } else {
                if (dpI[i+1][j]) continue;
                dpO[i+1][j+1] = max(dpO[i+1][j+1], dpI[i+1][j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            ans = max(ans, dpI[i][j]);
        }
    }

    cout << ans;

    return 0;
}