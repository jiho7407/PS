#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int TC, N, X;
int a[100010];

int main(){
    fastio();
    cin >> TC;
    while(TC--){
        cin >> N >> X;
        for(int i = 0; i<N; i++){
            cin >> a[i];
        }
        int ans = -1, goal = 0;
        for(int bit = 29; bit>=-1; bit--){
            if(bit == -1) goal = X;
            else{
                if(!(X&(1<<bit))) continue;
                goal = X | ((1<<bit)-1);
                goal ^= (1<<bit);
            }
            
            int cnt = 0, cur = 0;
            for(int i = 0; i<N; i++){
                cur ^= a[i];
                if((cur&goal) == cur){
                    cur = 0;
                    cnt++;
                }
            }
            if(cur==0) ans = max(ans, cnt);
        }
        cout << ans << "\n";
    }
    return 0;
}