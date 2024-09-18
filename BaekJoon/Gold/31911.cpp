#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N, K, M;
int cnt[255][255];
int nxt[255];

void solve(){
    cin >> N >> K >> M;
    rep(i, 0, N){
        string S; cin >> S;
        rep(i, 0, S.size()-1){
            cnt[(int)(S[i])][(int)(S[i+1])]++;
        }
    }
    rep(i, 0, 255){
        int idx = -1, mx = -1;
        rep(j, 0, 255){
            if(cnt[i][j] > mx){
                idx = j;
                mx = cnt[i][j];
            }
        }
        nxt[i] = idx;
        if(mx == 0) nxt[i] = (int)('.');
    }

    ll front, cycle;
    int cur = (int)('[');
    map<int, int> mp;
    int idx = 0;
    while(1){
        if(mp.find(cur) != mp.end()){
            front = mp[cur];
            cycle = mp.size() - front;
            break;
        }
        mp[cur] = idx++;
        cur = nxt[cur];
    }
    
    if(K <= front){
        cur = (int)('[');
        rep(i, 0, K-1) cur = nxt[cur];
    }
    else{
        K--;
        K -= front;
        K %= cycle;
        cur = (int)('[');
        rep(i, 0, front) cur = nxt[cur];
        rep(i, 0, K) cur = nxt[cur];
    }

    rep(i, 0, M){
        cout << (char)cur;
        cur = nxt[cur];
    }
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}