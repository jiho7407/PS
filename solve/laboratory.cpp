#include <bits/stdc++.h>

using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(NULL)
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll mod = 1e9 + 7;

int main() {
    fastio;
    int n;
    cin >> n;
    n--;
    for(int i = 0; i < n/2; i++){
        int x = i;
        for(int j = 1; j <= n; j++){
            cout << (x + (j/2) * (j % 2 == 0 ? 1 : -1) + n) % n + 1 << ' ';
        }
        cout << n+1;
        cout << endl;
    }
    return 0;
}