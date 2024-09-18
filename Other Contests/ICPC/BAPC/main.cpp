#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s[1010];
void solve(){
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++) cin >> s[i];
    string ans = "";

    for(int j = 0; j< M; j++) {
        int cnt[30] = {};
        int mx = 0;
        for(int i = 0; i < N; i++) cnt[s[i][j] - 'a']++;
        for(int i = 0; i < 26; i++) if(cnt[mx] < cnt[i]) mx = i;
        ans += 'a' + mx;
        }    cout << ans;




}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
/*
3 5
apple
maple
alpha

3 4
icpc
back
laps
*/