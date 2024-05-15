#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void solve(){
    int N, K, M;
    cin >> N >> K >> M;

    vector<int> lst(N);
    for (int i = 0; i < N; ++i) {
        lst[i] = i;
    }

    vector<bool> used(N, false);

    int idx = 0;
    int cnt = 0;
    int idxcnt = 0;
    bool reverse = false;

    while (cnt < N) {
        if (idxcnt == K && !used[idx]) {
            if (idx) {
                cout << idx << endl;
            } else {
                cout << N << endl;
            }
            used[idx] = true;
            cnt += 1;
            if (cnt % M == 0) {
                reverse = !reverse;
            }
            idxcnt = 0;
            if (cnt == N) {
                break;
            }
        }
        if (reverse) {
            idx -= 1;
            if (idx < 0) {
                idx = N - 1;
            }
            if (!used[idx]) {
                idxcnt += 1;
            }
        } else {
            idx += 1;
            if (idx >= N) {
                idx = 0;
            }
            if (!used[idx]) {
                idxcnt += 1;
            }
        }
    }

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