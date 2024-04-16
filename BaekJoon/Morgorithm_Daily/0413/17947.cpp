#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M, K;
int cards[400000];

void solve(){
    cin >> N >> M >> K;
    fill(cards, cards+K, (4*N)/K);
    for(int i = 1; i<=(4*N)%K; i++) cards[i]++;
    for(int i = 0; i<M; i++){
        int a, b;
        cin >> a >> b;
        cards[a%K]--;
        cards[b%K]--;
    }
    int A, B;
    cin >> A >> B;
    int score = max(A%K, B%K) - min(A%K, B%K);
    cards[A%K]--; cards[B%K]--;

    // for(int i = 0; i<K; i++){
    //     cout << cards[i] << ' ';
    // }
    // cout << '\n';
    int ans = 0;
    vector<int> lst;
    for(int i = 0; i<K; i++){
        for(int j = 0; j<cards[i]; j++) lst.push_back(i);
    }
    int ll = 0, rr = lst.size()/2;
    while(rr<lst.size()){
        int diff = lst[rr] - lst[ll];
        if(diff <= score){
            rr++;
        }
        else{
            ans += 1;
            ll++; rr++;
        }
    }
    cout << min(ans, M-1) << '\n';
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