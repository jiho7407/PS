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

const int mxN = 150;
int N, C;
vector<int> fishbowl;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void sort1(vector<int> &fishbowl){
    int DP[mxN][mxN];
    rep(i, 0, mxN) fill(DP[i], DP[i] + mxN, 0);
    rep(i, 0, N) DP[0][i] = fishbowl[i];\
    while(1){
        // 올릴 사이즈 재기
        int height = 1;
        while(DP[height][0] != 0) height++;
        int width = 1;
        while(DP[1][width] != 0) width++;
        int fullwidth = 0;
        while(DP[0][fullwidth] != 0) fullwidth++;

        // 넘어가면 탈출
        if(height > (fullwidth - width)) break;

        // 오른쪽으로 90도 회전 후 올리기
        rep(i, 0, height){
            rep(j, 0, width){
                DP[width-j][width+i] = DP[i][j];
            }
        }

        // 왼쪽으로 붙이기
        rep(i, 0, mxN) rep(j, width, mxN){
            DP[i][j-width] = DP[i][j];
            DP[i][j] = 0;
        }

        // 테스트 출력
        // cout << height << " " << width << "\n";
        // rep(i, 0, N){
        //     rep(j, 0, N) cout << DP[i][j] << " ";
        //     cout << "\n";
        // }
    }

    // 퍼뜨리는 과정
    int newDP[mxN][mxN];
    rep(i, 0, mxN) rep(j, 0, mxN) newDP[i][j] = DP[i][j];
    rep(i, 0, mxN) rep(j, 0, mxN){
        rep(k, 0, 4){
            int nx = i + dx[k], ny = j + dy[k];
            if(nx < 0 || nx >= mxN || ny < 0 || ny >= mxN) continue;
            if(DP[i][j] == 0 || DP[nx][ny] == 0) continue;
            int d = (DP[i][j] - DP[nx][ny])/5;
            if(d<=0) continue;
            newDP[i][j] -= d;
            newDP[nx][ny] += d;
        }
    }

    // 어항 피기
    vector<int> newfishbowl;
    rep(j, 0, mxN) rep(i, 0, mxN) if(newDP[i][j] != 0) newfishbowl.push_back(newDP[i][j]);
    fishbowl = newfishbowl;
    return;
}

void sort2(vector<int> &fishbowl){
    int DP[mxN][mxN];
    rep(i, 0, mxN) fill(DP[i], DP[i] + mxN, 0);
    rep(i, 0, N) DP[0][i] = fishbowl[i];
    rep(_, 0, 2){
        // 올릴 사이즈 재기
        int height = 1;
        while(DP[height][0] != 0) height++;
        int width = 1;
        while(DP[0][width] != 0) width++;

        rep(i, 0, height){
            rep(j, 0, width/2){
                DP[height*2-i-1][width - j - 1] = DP[i][j];
            }
        }

        // 왼쪽으로 붙이기
        rep(i, 0, mxN) rep(j, width/2, width){
            DP[i][j-width/2] = DP[i][j];
            DP[i][j] = 0;
        }

        // 테스트 출력
        // cout << height << " " << width << "\n";
        // rep(i, 0, N){
        //     rep(j, 0, N) cout << DP[i][j] << " ";
        //     cout << "\n";
        // }
    }

    // 퍼뜨리는 과정
    int newDP[mxN][mxN];
    rep(i, 0, mxN) rep(j, 0, mxN) newDP[i][j] = DP[i][j];
    rep(i, 0, mxN) rep(j, 0, mxN){
        rep(k, 0, 4){
            int nx = i + dx[k], ny = j + dy[k];
            if(nx < 0 || nx >= mxN || ny < 0 || ny >= mxN) continue;
            if(DP[i][j] == 0 || DP[nx][ny] == 0) continue;
            int d = (DP[i][j] - DP[nx][ny])/5;
            if(d<=0) continue;
            newDP[i][j] -= d;
            newDP[nx][ny] += d;
        }
    }

    // 어항 피기
    vector<int> newfishbowl;
    rep(j, 0, mxN) rep(i, 0, mxN) if(newDP[i][j] != 0) newfishbowl.push_back(newDP[i][j]);
    fishbowl = newfishbowl;
    return;
}

void solve(){
    cin >> N >> C;
    fishbowl.resize(N);
    rep(i, 0, N) cin >> fishbowl[i];
    int ans = 0;
    while(1){
        int mx = *max_element(fishbowl.begin(), fishbowl.end());
        int mn = *min_element(fishbowl.begin(), fishbowl.end());
        if(mx - mn <= C){
            cout << ans << "\n";
            return;
        }
        rep(i, 0, N) if(fishbowl[i] == mn) fishbowl[i]++;

        sort1(fishbowl);
        sort2(fishbowl);
        ans++;
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