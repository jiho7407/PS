#include <bits/stdc++.h>
using namespace std;

long long func1(long long a, long long b, long long c){
    if(b==1) return a%c;
    long long temp = func1(a, b/2, c);
    temp = temp*temp%c;
    if(b%2==0) return temp;
    else return temp*a%c;
}

int main(void){
    long long A, B, C;
    cin >> A >> B >> C;
    cout << func1(A%C, B, C)%C;
}