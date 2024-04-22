#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int H, W, N, ans;
pii stickers[100];

bool check(pii A, pii B){
    if(max(A.first, B.first) <= H && A.second+B.second <= W) return true;
    return false;
}

pii rotate(pii A){
    return {A.second, A.first};
}

void solve(){
    for(int i = 0; i<N-1; i++){
        for(int j = i+1; j<N; j++){
            pii A, B;
            A = stickers[i];
            B = stickers[j];
            int area = A.first*A.second + B.first*B.second;
            if(area<ans) continue;
            if(check(A, B)) ans = area;
            if(check(A, rotate(B))) ans = area;
            if(check(rotate(A), B)) ans = area;
            if(check(rotate(A), rotate(B))) ans = area;
        }
    }
}

int main(){
    fastio();
    cin >> H >> W;
    cin >> N;
    for(int i = 0; i<N; i++){
        int r, c;
        cin >> r >> c;
        stickers[i] = {r, c};
    }
    ans = 0;
    solve();
    swap(H, W);
    solve();
    cout << ans;
    return 0;
}