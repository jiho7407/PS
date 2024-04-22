#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}


vector<int> D;
int dp[310][1500];
int N, X, A[310], C[1500];
unordered_map<int, int> dct;

int euc(int a, int b){
    int r;
    if(a>b) swap(a, b);
    while(b!=0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

void finddivisor(int a, vector<int> &D){
    for(int i = 1; i*i<=a; i++){
        if(a%i) continue;
        if(i*i==a){
            D.push_back(i);
            break;
        }
        D.push_back(i);
        D.push_back(a/i);
    }
    sort(D.begin(), D.end());
}

int solve(int T, int G){
    if(T == N) return 1;
    if(dp[T][G] != 0) return dp[T][G];

    int result = 1;
    for(int i = 0; i<N; i++){
        int E = euc(D[G], A[i]);
        // cout << E << " ";
        if(E==1 || T >= C[dct[E]]) continue;

        if(solve(T+1, dct[E]) == 1){
            result = 2;
            break;
        }
    }

    dp[T][G] = result;
    return dp[T][G];
}

int main(){
    cin >> N >> X;
    for(int i = 0; i<N; i++){
        cin >> A[i];
    }

    // 약수 계산
    finddivisor(X, D);
    for(int i = 0; i<D.size(); i++){
        dct.insert({D[i], i});
    }

    // 각 약수별 배수 개수 계산
    fill(C, C+D.size(), 0);
    for(int i = 0; i<D.size(); i++){
        for(int j = 0; j<N; j++){
            if(A[j]%D[i]) continue;
            C[i]++;
        }
    }

    // dp 테이블 초기화, 0: 미도착, 1: 패배, 2: 승리
    for(int i = 0; i<N; i++){
        fill(dp[i], dp[i]+1500, 0);
    }

    if(solve(0, dct[X])==2) cout << "First";
    else cout << "Second";
}