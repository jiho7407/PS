#include <bits/stdc++.h>
using namespace std;

const int mx = 1000100;
string S, T;
int pi[mx];
int ans;
int anslst[mx];

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main(){
    fastio(); 
    getline(cin, S);
    getline(cin, T);
    int Slen, Tlen;
    Slen = S.length();
    Tlen = T.length();
    int pi[Tlen+1];
    fill(pi, pi+Tlen, 0);
    int k;
    for(int i=1; i<Tlen; i++){
        k = pi[i-1];
        while(k>0 && T[k] != T[i]){
            k = pi[k-1];
        }
        if(T[k] == T[i]){
            k++;
        }
        pi[i] = k;
    }
    int D[Slen];
    fill(D, D+Slen, 0);
    if(S[0] == T[0]) D[0] = 1;
    for(int i=1; i<Slen; i++){
        k = D[i-1];
        while(k>0 && T[k]!=S[i]){
            k = pi[k-1];
        }
        if(T[k]==S[i]){
            k++;
        }
        D[i]=k;
    }

    ans = 0;
    fill(anslst, anslst+mx, 0);
    for(int i = 0; i<Slen; i++){
        if(D[i] == Tlen){
            anslst[ans] = i-Tlen+2;
            ans++;
        }
    }
    cout << ans << "\n";
    for(int i = 0; i<ans; i++){
        cout << anslst[i] << "\n";
    }
}