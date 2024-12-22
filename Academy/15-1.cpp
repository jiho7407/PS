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

string Board[3][3] = {
    {"B", "B", "B"},
    {"B", "B", "B"},
    {"B", "B", "B"}
};

int val[3][3] = {
    {10, 10, 10},
    {10, 10, 10},
    {10, 10, 10}
};

int isEnd(){ // 0: 진행중, 1: X 승, 2: O 승, 3: 무승부
    // 가로 검사
    rep(i, 0, 3){
        if(Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2]){
            if(Board[i][0] == "X") return 1;
            if(Board[i][0] == "O") return 2;
        }
    }

    // 세로 검사
    rep(j, 0, 3){
        if(Board[0][j] == Board[1][j] && Board[1][j] == Board[2][j]){
            if(Board[0][j] == "X") return 1;
            if(Board[0][j] == "O") return 2;
        }
    }

    // 대각선 검사
    if(Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2]){
        if(Board[0][0] == "X") return 1;
        if(Board[0][0] == "O") return 2;
    }

    if(Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0]){
        if(Board[0][2] == "X") return 1;
        if(Board[0][2] == "O") return 2;
    }

    // 칸이 전부 참
    rep(i, 0, 3){
        rep(j, 0, 3){
            if(Board[i][j] == "B") return 0;
        }
    }

    return 3;
}

bool isXTurn(){
    int xcnt = 0, ocnt = 0;
    rep(i, 0, 3){
        rep(j, 0, 3){
            if(Board[i][j] == "X") xcnt++;
            if(Board[i][j] == "O") ocnt++;
        }
    }
    return xcnt == ocnt;
}

float calcXScore(int state){
    int xcost = 0, score = 0;
    rep(i, 0, 3) rep(j, 0, 3){
        if(Board[i][j] == "B") continue;
        if(Board[i][j] == "X") xcost += val[i][j];
        score += val[i][j];
    }

    if(state == 1) return score - xcost;
    if(state == 2) return -xcost;
    if(state == 3) return (float)score/2 - xcost;

    cout << "Error\n";
    return 0;
}

float calc(){
    int state = isEnd();
    if(state != 0){
        // rep(i, 0, 3){
        //     rep(j, 0, 3){
        //         cout << Board[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << "Score: " << calcXScore(state) << '\n';
        // cout << "=====================\n";
        return calcXScore(state);
    }
    float ret;
    if(isXTurn()){
        ret = -1e9;
        rep(i, 0, 3) rep(j, 0, 3){
            if(Board[i][j] == "B"){
                Board[i][j] = "X";
                ret = max(ret, calc());
                Board[i][j] = "B";
            }
        }
    }
    else{
        ret = 1e9;
        rep(i, 0, 3) rep(j, 0, 3){
            if(Board[i][j] == "B"){
                Board[i][j] = "O";
                ret = min(ret, calc());
                Board[i][j] = "B";
            }
        }
    }

    // rep(i, 0, 3){
    //     rep(j, 0, 3){
    //         cout << Board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "Score: " << ret << '\n';
    // cout << "=====================\n";
    return ret;
}

void solve(){
    rep(i, 0, 3) rep(j, 0, 3) cin >> val[i][j];
    rep(i, 0, 3) rep(j, 0, 3) cin >> Board[i][j];
    cout << fixed << setprecision(2);
    cout << calc() << '\n';
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


// -40
// -5
// 9
// -23
// 44
// 10
// -7
// -17
// 104
// 24