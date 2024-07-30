#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

string board[10];

int check1(int x, int y, int sz){ // 오른쪽 아래 빗변
    int ret = 0;
    rep(i, 0, sz) rep(j, 0, sz - i){
        int cx = x + i, cy = y + j;
        if(cx < 0 || cy < 0 || cx >= 10 || cy >= 10) continue;
        board[cx][cy] = '1';
        if(board[cx][cy] == '1') ret++;
        else return -1;
    }
    return ret;
}

int check2(int x, int y, int sz){ // 오른쪽 위 빗변
    int ret = 0;
    rep(i, 0, sz) rep(j, 0, i+1){
        int cx = x + i, cy = y + j;
        if(cx < 0 || cy < 0 || cx >= 10 || cy >= 10) continue;
        board[cx][cy] = '1';
        // cout << cx << ' ' << cy << ' ' << board[cx][cy] << '\n';
        if(board[cx][cy] == '1') ret++;
        else return -1;
    }
    return ret;
}

int check3(int x, int y, int sz){ // 왼쪽 빗변
    int ret = 0;
    ret += check2(x, y, sz);
    ret += check1(x+sz-1, y, sz);
    // cout << check2(x, y, sz) << ' ' << check1(x+sz-1, y, sz) << '\n';
    if(x + sz - 1 < 10){
        rep(j, 0, sz){
            int cx = x + sz - 1, cy = y + j;
            if(cy < 0 || cy >= 10) continue;
            if(board[cx][cy] == '1') ret--;
        }
    }
    return ret;
}

void rotate(){
    char tmp[10][10];
    rep(i, 0, 10) rep(j, 0, 10) tmp[i][j] = board[j][9-i];
    rep(i, 0, 10) rep(j, 0, 10) board[i][j] = tmp[i][j];
}

pii rotate2(pii c, int cnt){
    if(cnt == 0) return c;
    return rotate2({c.second, 9-c.first}, cnt-1);
}

void print(pii p1, pii p2, pii p3){
    vector<pii> ans = {p1, p2, p3};
    sort(ans.begin(), ans.end());
    cout << ans[0].first+1 << ' ' << ans[0].second+1 << '\n';
    cout << ans[1].first+1 << ' ' << ans[1].second+1 << '\n';
    cout << ans[2].first+1 << ' ' << ans[2].second+1 << '\n';
}

void solve(){
    rep(i, 0, 10) cin >> board[i];
    int all = 0;
    rep(i, 0, 10) rep(j, 0, 10) if(board[i][j] == '1') all++;

    cout << '\n';
    cout << check1(1, 1, 10) << '\n';
    rep(i, 0, 10){
        rep(j, 0, 10) cout << board[i][j];
        cout << '\n';
    }

    // if(all <= 1){
    //     cout << 0 << '\n';
    //     return;
    // }
    
    // rep(r, 0, 4){
    //     rep(i, 0, 10) rep(j, 0, 10) rep(sz, 1, 11){
    //         if(check1(i, j, sz) == all){ // 오른쪽위 빗변
    //             // cout << "case 1 " << r << ' ' << i << ' ' << j << ' ' << sz << '\n';
    //             pii p1 = rotate2({i, j}, r);
    //             pii p2 = rotate2({i+sz-1, j}, r);
    //             pii p3 = rotate2({i, j+sz-1}, r);
    //             print(p1, p2, p3);
    //             return;
    //         }
    //         else if(check3(i, j, sz) == all){ // 왼쪽 빗변
    //             // cout << "case 2 " << r << ' ' << i << ' ' << j << ' ' << sz << '\n';
    //             pii p1 = rotate2({i, j}, r);
    //             pii p2 = rotate2({i+sz-1, j+sz-1}, r);
    //             pii p3 = rotate2({i+2*sz-2, j}, r);
    //             print(p1, p2, p3);
    //             return;
    //         }
    //     }
    //     rotate();
    // }
    // cout << 0 << '\n';
    return;
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