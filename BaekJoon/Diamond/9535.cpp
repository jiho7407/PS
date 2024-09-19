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

int N, M;
int board[100][100];
vector<pair<bool, int>> v;

bool check(int i, int j){
    if(board[i][j] == i*M+j+1) return true;
    return false;
}

void swapx(int idx){
    v.push_back({0, idx});
    rep(i, 0, M/2) swap(board[idx][i], board[idx][M-i-1]);
}

void swapy(int idx){
    v.push_back({1, idx});
    rep(i, 0, N/2) swap(board[i][idx], board[N-i-1][idx]);
}

void rot(int x, int y){
    rep(i, 0, 3){
        if(check(x, y)) continue;
        rep(j, 0, 2){
            swapx(N-x-1);
            swapy(y);
        }
    }
    rep(i, 0, 3){
        if(check(x, y)) continue;
        rep(j, 0, 2){
            swapy(M-y-1);
            swapx(x);
        }
    }
    rep(i, 0, 3){
        if(check(N-x-1, M-y-1)) continue;
        rep(j, 0, 2){
            swapx(N-x-1);
            swapy(M-y-1);
        }
    }
}

void xdiag(int x, int y){
    swapx(x);
    swapy(y);
    swapx(x);
}

void ydiag(int x, int y){
    swapy(y);
    swapx(x);
    swapy(y);
}

void prt(){
    rep(i, 0, N){
        rep(j, 0, M) cout << board[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

void solve(){
    cin >> M >> N;
    rep(i, 0, N) rep(j, 0, M) cin >> board[i][j];

    rep(i, 0, N/2) rep(j, 0, M/2){
        rot(i, j);
        if(!check(N-i-1, j)){
            if(j == 0) ydiag(i, j);
            else xdiag(i, j);
        }
        // prt();
    }

    if(N%2 && !check(N/2, 0)) swapx(N/2);
    if(M%2 && !check(0, M/2)) swapy(M/2);

    bool flag = true;
    rep(i, 0, N) rep(j, 0, M) if(!check(i, j)) flag = false;
    if(flag){
        if(v.size() > 10*N*M) assert(false);
        cout << "POSSIBLE " << v.size() << ' ';
        for(auto [a, b]: v){
            if(a) cout << 'C' << b+1 << ' ';
            else cout << 'R' << b+1 << ' ';
        }
        cout << '\n';
    }
    else cout << "IMPOSSIBLE\n";

    v.clear();
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}