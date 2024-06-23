#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = int(1e9) + 7;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
str CAA, CAB, CBA, CBB;
ll mat[4][4];
map<str, int> mp = {{"AA", 0}, {"AB", 1}, {"BA", 2}, {"BB", 3}};
ll dp[1001][4];
int sz[4];

void matpow(int n){
    if(n == 1) return;
    matpow(n/2);
    ll temp[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            temp[i][j] = 0;
            for(int k = 0; k < 4; k++){
                temp[i][j] += mat[i][k] * mat[k][j];
                temp[i][j] %= mod;
            }
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            mat[i][j] = temp[i][j];
        }
    }
    if(n%2){
        ll temp[4][4];
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                temp[i][j] = 0;
                for(int k = 0; k < 4; k++){
                    temp[i][j] += mat[i][k] * mat[k][j];
                    temp[i][j] %= mod;
                }
            }
        }
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                mat[i][j] = temp[i][j];
            }
        }
    }
}

void solve(){
    cin >> N;
    cin >> CAA >> CAB >> CBA >> CBB;
    sz[0] = CAA.size();
    sz[1] = CAB.size();
    sz[2] = CBA.size();
    sz[3] = CBB.size();
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            mat[i][j] = 0;
        }
    }

    if(CAA[CAA.size()-1] == 'A') mat[mp["AA"]][0]++;
    else mat[mp["BA"]][0]++;
    if(CAA[0] == 'A') mat[mp["AA"]][0]++;
    else mat[mp["AB"]][0]++;

    if(CAB[CAB.size()-1] == 'A') mat[mp["AB"]][1]++;
    else mat[mp["BB"]][1]++;
    if(CAB[0] == 'A') mat[mp["AA"]][1]++;
    else mat[mp["AB"]][1]++;

    if(CBA[CBA.size()-1] == 'A') mat[mp["AA"]][2]++;
    else mat[mp["BA"]][2]++;
    if(CBA[0] == 'A') mat[mp["BA"]][2]++;
    else mat[mp["BB"]][2]++;

    if(CBB[CBB.size()-1] == 'A') mat[mp["AB"]][3]++;
    else mat[mp["BB"]][3]++;
    if(CBB[0] == 'A') mat[mp["BA"]][3]++;
    else mat[mp["BB"]][3]++;

    matpow(N-2);
    cout << "mat:" << endl;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
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