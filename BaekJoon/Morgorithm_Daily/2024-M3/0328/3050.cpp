#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
vector<int> pf[400];

int main(){
    fastio();
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        string line;
        cin >> line;
        pf[i].push_back(0);
        int cnt = 0;
        for(int j = 0; j<M; j++){
            if(line[j] == 'X') cnt++;
            pf[i].push_back(cnt);
        }
    }   

    int ans = 0;
    for(int i = 0; i<N; i++){
        int l = 1;
        while(l<=M){
            int r = l;
            while(r<=M && pf[i][r] - pf[i][l-1] == 0){
                int h = i;
                while(h < N && pf[h][r] - pf[h][l-1] == 0) h++;
                ans = max(ans, (r-l+1) + (h-i));
                r++;
            }
            l++;
        }
    }

    if(ans==0) cout << 0;
    else cout << ans*2-1;

    return 0;
}