#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> lst(N);
    for (int i = 0; i < N; i++) {
        cin >> lst[i];
    }

    vector<pair<int, int>> S(N + 1);
    S[0] = {0, 0};
    for (int i = 1; i <= N; i++) {
        S[i] = {S[i-1].first + lst[i-1], i};
    }

    sort(S.begin(), S.end());

    N += 1;
    vector<int> tree(2 * N, 0);

    int Nidx = N;
    while(Nidx > 0){
        tree[Nidx] = 1;
        Nidx /= 2;
    }

    long long ans = 0;
    bool answered = false;

    for (int i = 0; i < N; i++) {
        if (S[i].first < 0 || S[i].second == 0) {
            continue;
        }

        int cmd = S[i].second;

        long long temp = 0;

        int s = N;
        int e = N + cmd;
        while (s < e) {
            if (s % 2) {
                temp += tree[s];
                s++;
            }
            if (e % 2) {
                e--;
                temp += tree[e];
            }
            s /= 2;
            e /= 2;
            temp %= MOD;
        }

        int idx;
        idx = N + cmd;
        while(idx > 0){
            tree[idx] += temp;
            tree[idx] %= MOD;
            idx /= 2;
        }

        if (cmd == N-1) {
            cout << tree[2*N-1] % MOD << "\n";
            answered = true;
            break;
        }
    }
    if (!answered) {
        cout << 0 << "\n";
    }

    return 0;
}