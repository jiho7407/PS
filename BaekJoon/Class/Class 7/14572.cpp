#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, K, D;
pii abil[100000];
vector<int> algo[100000];
vector<int> curalgo;

bool cmp(pii a, pii b){
    return a.second < b.second;
}

void solve(){
    cin >> N >> K >> D;
    for(int i = 0; i<N; i++){
        int M, d;
        cin >> M >> d;
        abil[i] = {i, d};
        for(int j = 0; j<M; j++){
            int a;
            cin >> a;
            algo[i].push_back(a);
        }
    }

    sort(abil, abil+N, cmp);
    int l = 0, r = 0;
    int ans = 0;
    curalgo.resize(K+1, 0);
    int algocnt = 0;
    while(r < N){
        while(r<N && abil[r].second - abil[l].second <= D){
            for(auto know: algo[abil[r].first]){
                if(curalgo[know]++ == 0) algocnt++;
            }
            r++;
        }
        int allknow = 0;
        for(int i = 1; i<=K; i++){
            if(curalgo[i]==r-l) allknow++;
        }
        ans = max(ans, (algocnt - allknow)*(r-l));
        for(auto know: algo[abil[l].first]){
            if(--curalgo[know] == 0) algocnt--;
        }
        l++;
    }
    cout << ans << '\n';
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}