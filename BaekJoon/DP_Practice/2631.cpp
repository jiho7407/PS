#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
int num[1000];
int curln[1000];
int curmx[1000];

int main(){
    fastio();
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> num[i];
    }
    fill(curln, curln+N, 0);
    fill(curmx, curmx+N, 0);

    for(int i = 0; i<N; i++){
        curln[i] = 1, curmx[i] = num[i];
        for(int j = 0; j<i; j++){
            if(curmx[j] >= num[i]) continue;
            if(curln[j] < curln[i]) continue;
            curln[i] = curln[j]+1;
        }
    }
    
    int result = 0;
    for(int i = 0; i<N; i++){
        result = max(result, curln[i]);
    }
    cout << N -result;
    return 0;
}