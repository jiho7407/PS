#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int M;
pair<int, int> arr[100010];

void solve(){
    cin >> M;
    int i = 0;
    while(1){
        int l, r;
        cin >> l >> r;
        if(l == 0 && r == 0) break;
        arr[i++] = {l, r};
    }
    sort(arr, arr+i, [](pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    });
    int cur = 0, mx = -100000, cnt = 0;
    for(int j = 0; j < i; j++){
        if(arr[j].first <= cur){
            mx = max(mx, arr[j].second);
        }
        else{
            if(mx <= cur){
                cout << 0;
                return;
            }
            cnt++;
            cur = mx;
            if(arr[j].first > cur){
                cout << 0;
                return;
            }
            if(cur >= M){
                cout << cnt;
                return;
            }
        }
    }
    if(mx <= cur){
        cout << 0;
        return;
    }
    else{
        cur = mx;
        cnt++;
        if(cur >= M){
            cout << cnt;
            return;
        }
    }
    return;
}

int main(){
    fastio();
    solve();
    return 0;
}