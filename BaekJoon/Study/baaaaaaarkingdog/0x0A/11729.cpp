#include <bits/stdc++.h>
using namespace std;

int Hanoi(int cur, int goal, int n){
    if(n==0) return 0;
    int temp = 6-cur-goal;
    Hanoi(cur, temp, n-1);
    cout << cur << " " << goal << "\n";
    Hanoi(temp, goal, n-1);
    return 0;
}

int main(void){
    int N;
    cin >> N;
    int temp = pow(2, N) - 1;
    cout << temp << "\n";
    Hanoi(1, 3, N);
}