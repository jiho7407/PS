#include <bits/stdc++.h>
using namespace std;

int recursiveNto1(int a){
    if(a==0) return 0;
    return a + recursiveNto1(a-1);
}

int main(void){
    int a[2000][2000];
    cout << recursiveNto1(10);
}