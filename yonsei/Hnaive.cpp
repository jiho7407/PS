#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}


ll X, K, C;
ll p[110];

void print(){
    ll ret = 0;
    rep(i, 0, X){
        if(p[i] == 0) break;
        // cout << p[i] << ' ';
        ret += p[i] + C;
    }
    ret += K*(p[0]+C);
    if(ret > 760) return;
    rep(i, 0, X){
        if(p[i] == 0) break;
        cout << p[i] << ' ';
    }
    cout << ret << '\n';
}

void solve(){
    int i, j;
    cin >> X >> K >> C;
    p[0] = X;
    rep(i, 1, 110) p[i] = 0;
 
    // 최초 설정
    p[0] = X;
    for (i = 1; i < X; i++) {
        p[i] = 0;
    }
    print();
 
    // 가장 왼쪽이 1이 될때까지 반복
    while (p[0] != 1) {
        // 오른쪽 부터 조사해서 1이 아니면 바로 옆에다 두기
        for (i = X; i >= 0; i--) {
            if (p[i] > 1) {
                p[i]--;
                p[i + 1]++;
 
                // 만약 2보다 클 경우, 바로 옆에다 전부 모으기
                if (X > 2) {
                    for (j = i + 2; j < X; j++) {
                        p[i + 1] += p[j];
                        p[j] = 0;
                    }
                }
 
                // 전부 모았을 때, 앞의 것보다 크면
                while (p[i] < p[i + 1]) {
                    p[i + 2] = p[i + 1];
                    p[i + 1] = p[i];
                    p[i + 2] -= p[i + 1];
                    i++;
                }
 
                // 출력
                print();
                break;
            }
        }
    }
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}