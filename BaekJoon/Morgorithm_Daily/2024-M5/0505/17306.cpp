#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
int tridx = 0;
vector<int> DP;

struct Trie{
    Trie* child[2];
    bool isEnd;
    Trie(){
        child[0] = child[1] = nullptr;
    }
    void insert(ll x){
        ll t = __builtin_clzll(x);
        string s = bitset<64>(x).to_string().substr(t, 64-t);
        Trie* cur = this;
        for(auto c : s){
            if(!cur->child[c-'0']) cur->child[c-'0'] = new Trie();
            cur = cur->child[c-'0'];
        }
        cur->isEnd = true;
    }

    ll query(ll x){
        int cur = tridx;
        ll ret;
        if(isEnd) ret = 1;
        else ret = 0;
        rep(i, 0, 2){
            if(child[i]) ret += child[i]->query(tridx++);
        }
        // cout << cur << ' ' << ret << '\n';
        return DP[cur] = ret;
    }
}trie;

void solve(){
    cin >> N;
    rep(i, 0, N){
        ll x; cin >> x;
        trie.insert(x);
    }
    DP.resize(N*50, 0);
    trie.query(0);
    int ans = 0;
    rep(i, 0, N*50) if(0 < DP[i] && DP[i] < N) ans++;
    cout << ans+1 << '\n';
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;   ㅁ
    while(tc--){
        solve();
    }
    return 0;
}