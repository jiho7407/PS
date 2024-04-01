#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int INF = 10000;
int N;
string board;
bool visited[100][100];
pii DP[100][100];
int match[100][100];

pii solve(int l, int r){
    if(visited[l][r]) return DP[l][r];
    if(l>=r) return {0, 1};
    visited[l][r] = true;

    for(int m = l+1; m<=r; m+=2){
        if(board[l] == board[m]) continue;
        pii inn = solve(l+1, m-1);
        pii out = solve(m+1, r);
        int res = inn.first + out.first + (inn.second)*2 + (m-l);
        if(DP[l][r].first > res){
            DP[l][r] = {res, max(inn.second+1, out.second)};
            match[l][r] = m;
        }
    }

    return DP[l][r];
}

void matching(int l, int r){
	int m = match[l][r];
	cout << l+1 << " " << m+1 << "\n";
    if(m-l >= 2) matching(l+1, m-1);
    if(r-m >= 2) matching(m+1, r);
}

int main(){
    fastio();
    cin >> N;
    cin >> board;
    for(int i = 0; i<N; i++) {fill(DP[i], DP[i]+N, pii(INF, 0)); fill(visited[i], visited[i]+N, false);}
    cout << solve(0, N-1).first << "\n";
    matching(0, N-1);
    return 0;
}