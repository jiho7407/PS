#include <bits/stdc++.h>
using namespace std;

int x=0, y=0;

void PW(int n, int k,int rt){ //rt = 0 : ∩, 1:⊃, 2:∪, 3:⊂
    // cout << n << " " << k << " " << rt << " " << x << y << "\n";
    if(n==1){
        x++;
        y++;
        return;
    }
    int quarter = n*n/4;
    if(k <= quarter){
        if(rt == 2 || rt == 3){
            x += n/2;
            y += n/2;
        }
        if(rt == 0 || rt == 2) PW(n/2, k, (rt+1)%4);
        else PW(n/2, k, (rt+3)%4);
    }
    else if(k <= 2*quarter){
        if(rt == 1 || rt == 2){
            x += n/2;
        }else{
            y += n/2;
        }
        PW(n/2, k-quarter, rt);
    }
    
    else if(k <= 3*quarter){
        if(rt == 0 || rt == 1){
            x += n/2;
            y += n/2;
        }
        PW(n/2, k-2*quarter, rt);
    }
    else{
        if(rt == 1 || rt == 2){
            y += n/2;
        }else{
            x += n/2;
        }
        if(rt == 0 || rt == 2) PW(n/2, k-3*quarter, (rt+3)%4);
        else PW(n/2, k-3*quarter, (rt+1)%4);
    }
    return;
}

int main(void){
    int N, M;
    cin >> N >> M;
    PW(N, M, 0);
    cout << x << " " << y;
    // for(int i=1; i<=64; i++){
    //     x=0;
    //     y=0;
    //     PW(8, i, 0);
    //     cout << x << " " << y << "\n";
    // }
}