#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, A, B;

int main(){
    fastio();
    cin >> N;
    A=0; B=0;
    while(N--){
        int a, b;
        cin >> a >> b;
        A += a;
        B += b;
    }
    if(A>B) cout << "Takahashi";
    else if(A<B) cout << "Aoki";
    else cout << "Draw";
    return 0;
}