#include <bits/stdc++.h>
using namespace std;

int Z(int N, int r, int c){
    if(N==0) return 0;
    int cut;
    cut = 1<<(N-1);
    int block = pow(cut, 2);
    if(r<cut && c<cut) return Z(N-1, r, c);
    else if(r<cut && c>=cut) return block + Z(N-1, r, c-cut);
    else if(r>=cut && c<cut) return 2*block + Z(N-1, r-cut, c);
    else return 3*block + Z(N-1, r-cut, c-cut);
}

int main(void){
    int N, r, c;
    cin >> N >> r >> c;
    cout << Z(N, r, c);
}