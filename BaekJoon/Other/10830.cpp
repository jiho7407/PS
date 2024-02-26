#include <bits/stdc++.h>
using namespace std;

const int mxnxt = 26;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

long long N, B;
int mat[10][10];
int ans[10][10];


auto matcalc(int mat1[10][10], int mat2[10][10]){
    int _tmpmat[10][10];
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            _tmpmat[i][j] = 0;
            for(int k = 0; k<N; k++){
                _tmpmat[i][j] += mat1[i][k]*mat2[k][j];
                _tmpmat[i][j] %= 1000;
            }
        }
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            mat1[i][j] = _tmpmat[i][j];
        }
    }
}

void matpow(int _mat[10][10], long long _B){
    for(int i = 0; i<N; i++){
        fill(ans[i], ans[i]+N, 0);
        ans[i][i] = 1;
    }
    while(_B>0){
        if(_B%2) matcalc(ans, mat);
        matcalc(mat, mat);
        _B /= 2;
    }
}


int main(){
    cin >> N >> B;
    int emt;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> emt;
            mat[i][j] = emt;
        }
    }
    matpow(mat, B);
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}