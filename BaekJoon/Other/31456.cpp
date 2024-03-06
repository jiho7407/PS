#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
int ans;

void print(int a, int b){
    cout << a << " " << b << "\n";
    ans++;
}

int main(){
    fastio();
    ans = 0;
    int N;
    cin >> N;
    
    if(N==1){
        cout << 1 << "\n";
        cout << "0 2";
        return 0;
    }
    if(N%2){
        cout << (N/2)*(N+4)+1 << "\n";
        for(int i = 2; i<=N-3; i+=2){
            print(0, 1);
            for(int j = 2; j<=N-i-1; j+=2){
                print(j-2, j);
            }
            print(N-i-1, N-i);
            for(int j = 3; j<=N-i; j+=2){
                print(j-2, j);
            }
        }
        for(int i = 2; i<=N-1; i+=2){
            print(i-2, i);
        }
        print(N-1, N);
        print(0, 1);
        for(int i = 2; i<=N+1; i+=2){
            print(i-2, i);
        }
        print(1, 2);
        for(int i = 4; i<=N-1; i+=2){
            print(i-2, i);
        }
        print(N-1, N+1);
        print(N, N+1);
        for(int i = 3; i<=N-2; i+=2){
            print(i, i+1);
            for(int j = i; j<=N-2; j+=2){
                print(j, j+2);
            }
            print(N, N+1);

            for(int j = i+1; j<=N-1; j+=2){
                print(j, j+2);
            }
        }
    }
    else{
        cout << N*(N/2+2)-1 << "\n";
        for(int i = 2; i<=N-2; i+=2){
            print(0, 1);
            for(int j = 2; j<=N-i; j+=2){
                print(j-2, j);
            }
            for(int j = 3; j<=N-i-1; j+=2){
                print(j-2, j);
            }
            print(N-i-1, N-i);
        }
        for(int i = 0; i<=N-2; i+=2){
            print(i, i+1);
            for(int j = i+1; j<=N-3; j+=2){
                print(j, j+2);
            }
            print(N-1, N);

            print(i, i+1);
            for(int j = i+1; j<=N-1; j+=2){
                print(j, j+2);
            }
            print(N, N+1);
        }
    }
    cout << ans;
    return 0;
}