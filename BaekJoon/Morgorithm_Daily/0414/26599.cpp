#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void solve(){
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> dragons(N);
    for (int i = 0; i < N; ++i) {
        cin >> dragons[i].first;
        dragons[i].second = i + 1;
    }

    sort(dragons.begin(), dragons.end());

    if (N <= 3) {
        if (N <= 2) {
            cout << "YES" << endl;
            for (int i = 1; i <= N; ++i) {
                cout << i << " ";
            }
            cout << endl;
        } else if (N == 3) {
            if (dragons[1].first - dragons[0].first > M || dragons[2].first - dragons[1].first > M) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
                for(int i = 0; i < N; ++i) {
                    cout << dragons[i].second << " ";
                }
            }
        }
        return;
    }

    if (dragons[N-1].first - dragons[N-2].first > M || dragons[N-2].first - dragons[N-3].first > M || dragons[N-3].first - dragons[N-4].first > M) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    cout << dragons[N-1].second << " ";
    cout << dragons[N-2].second << " ";
    for (int i = 0; i < N-2; ++i) {
        cout << dragons[i].second << " ";
    }
    cout << endl;
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