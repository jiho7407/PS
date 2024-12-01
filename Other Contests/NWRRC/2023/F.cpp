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

int N, A[100], B[100];
string DP[100][100][100];

string dfs(int aidx, int bidx, int ln){
    if(ln == 0) return "";
    if(DP[aidx][bidx][ln] != "") return DP[aidx][bidx][ln];

    string &ret = DP[aidx][bidx][ln];
    
    // 나이브하게 가능
    bool flag = true;
    rep(i, 0, ln) if(A[aidx+i] != B[bidx+i]) flag = false;
    if(flag){
        rep(i, 0, ln) ret += "SC";
        return ret;
    }

    // 스택에 넣고, 진행후 빼기
    if(A[aidx] == B[bidx+ln-1]){
        string ret1 = dfs(aidx+1, bidx, ln-1);
        if(ret1 != "X"){
            ret = "S" + ret1 + "C";
            return ret;
        }
    }

    // 좌우로 분할해서 진행
    rep(i, 1, ln){
        string ret1 = dfs(aidx, bidx, i);
        string ret2 = dfs(aidx+i, bidx+i, ln-i);
        if(ret1 != "X" && ret2 != "X"){
            ret = ret1 + ret2;
            return ret;
        }
    }

    return ret = "X";
}

void solve(){ 
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];

    string ret = dfs(0, 0, N);
    if(ret == "X") cout << "NO\n";
    else cout << "YES\n" << ret << '\n';
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