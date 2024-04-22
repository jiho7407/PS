#include <bits/stdc++.h>
using namespace std;

int arra[1000005];
int arrb[1000005];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int asize, bsize;
    cin >> asize >> bsize;
    for(int i = 0; i<asize; i++){
        cin >> arra[i];
    }
    for(int i = 0; i<bsize; i++){
        cin >> arrb[i];
    }
    int apoint=0, bpoint=0;
    for(int i = 0; i<asize+bsize; i++){
        if(bpoint >= bsize || apoint < asize && arra[apoint] < arrb[bpoint])cout << arra[apoint++] << " ";
        else cout << arrb[bpoint++] << " ";
    }
}