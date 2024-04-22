#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
int lst[100000];
vector<pii> spots;

bool cmp(pii A, pii B){
    return A.first < B.first;
}

int main(){
    fastio();
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        int P, C;
        cin >> P >> C;
        spots.push_back({P, C});
    }
    sort(spots.begin(), spots.end(), cmp);

    long long ans = spots[0].second;
    for(int i = 1; i<N; i++) ans += max(0, spots[i].second - spots[i-1].second);
    cout << ans;
    return 0;
}