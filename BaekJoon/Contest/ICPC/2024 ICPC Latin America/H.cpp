#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> getfail(const string& A) {
    int N = A.length();
    vector<int> fail(N);
    fail[0] = 0;
    for (int i = 1; i <= N; i++) {
        int j = fail[i - 1];
        while (j > 0 && A[j] != A[i]) { j = fail[j - 1]; }
        if (A[j] == A[i]) { fail[i] = j + 1; }
    }
    return fail;
}

vector<int> match(const string& T, const string P){
    vector<int> ret;
    int N = T.size(), M = P.size();
    if(N < M) return ret;
    vector<int> fail = getfail(P);
    for(int i = 0, j = 0; i<N; i++){
        while(j > 0 && T[i] != P[j]) j = fail[j-1];
        if(T[i] == P[j]){
            if(j == M-1){
                ret.push_back(i-M+1);
                j = fail[j];
            }
            else j++;
        }
    }
    return ret;
}

string S;
int N, K, sz;
ll DP[2][200100]; // 인버전 유무, 오른쪽으로 밀린 칸수
vector<int> kmp, mc;

bool invmatch = false;
int diff;
ll ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S;
    N = S.length();
    kmp = getfail(S);
    if(N % (N - kmp.back()) == 0) sz = N - kmp.back();
    else sz = N;

    string T = S + S;
    reverse(T.begin(), T.end());
    mc = match(T, S);
    if(!mc.empty()){
        invmatch = true;
        diff = N - mc[0];
    }

    DP[0][0] = 1;
    int CI = 0, CM = 0;
    cin >> K;
    while(K--){
        char op; cin >> op;
        if(op == 'I'){
            CI ^= 1;
            CM = (sz-CM)%sz;
        }
        else{
            int move;
            cin >> move;
            if(op == 'L') move = sz - move;
            CM = (CM + move%sz + sz) % sz;
        }
        ans += DP[CI][CM];
        if(invmatch) ans += DP[CI^1][(diff-CM+sz)%sz];
        DP[CI][CM]++;
    }
    cout << ans;
}