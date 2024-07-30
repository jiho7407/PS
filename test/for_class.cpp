#include <bits/stdc++.h>
using namespace std;

int arr[101];

int main(){
    int A = 100000, B = 100000, mod = 10;
    cout << (A*B)%mod << '\n'; // 8
    cout << ((long long)A * (long long)B) % (long long) mod << '\n'; // 0
    cout << ((A%mod)*(B%mod))%mod << '\n'; // 0
    
    return 0;
}




