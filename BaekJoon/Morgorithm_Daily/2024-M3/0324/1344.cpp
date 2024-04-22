#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

double A, B;
double Ap, Bp;
double tempA, tempB;
int ps[7] = {2, 3, 5, 7, 11, 13, 17};
long long fact[19];

void calc(){
    fact[0] = 1;
    for(int i = 1; i<=18; i++){
        fact[i] = fact[i-1]*i;
    }
}

int main(){
    fastio();
    calc();
    cin >> A >> B;
    Ap = A/100;
    Bp = B/100;
    vector<double> As, Bs;
    double Asum=0, Bsum=0;
    for(auto score: ps){
        tempA = tempB = fact[18]/(fact[score]*fact[18-score]);
        for(int j = 0; j<score; j++){
            tempA *= Ap;
            tempB *= Bp;
        }
        for(int j = score; j<18; j++){
            tempA *= (1-Ap);
            tempB *= (1-Bp);
        }
        As.push_back(tempA);
        Bs.push_back(tempB);
        Asum += tempA;
        Bsum += tempB;
    }
    double ans = 0;
    for(int i = 0; i<7; i++){
        ans += As[i];
        ans += Bs[i];
    }
    ans -= Asum*Bsum;
    cout << fixed << setprecision(16);
    cout << ans;
    return 0;
}