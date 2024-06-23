#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxbit = 30;

struct Trie{
    int cnt;

    Trie* next[2];
    Trie(){
        next[0] = next[1] = nullptr;
        cnt = 0;
    }
    ~Trie(){
        rep(i, 0, 2) if(next[i]) delete next[i];
    }

    void insert(ll x, ll bit){
        cnt++;
        if(bit == -1) return;
        ll b = (x>>bit)&1;
        if(!next[b]) next[b] = new Trie();
        next[b]->insert(x, bit-1);
    }

    void remove(ll x, ll bit){
        cnt--;
        if(bit == -1) return;
        ll b = (x>>bit)&1;
        next[b]->remove(x, bit-1);
    }

    void update(ll x, ll bit){
        if(bit == -1) return;
        ll b = (x>>bit)&1;
        if(b) swap(next[0], next[1]);

        if(next[0]) next[0]->update(x, bit-1);
        if(next[1]) next[1]->update(x, bit-1);
    }
};

int Q;

void dfs(Trie* cur, int bit, int val){
    cout << val << ' ' << bit << ' ' << cur->cnt << '\n';
    cout << cur->next[0] << ' ' << cur->next[1] << '\n';
    if(cur->next[1]) dfs(cur->next[1], bit-1, val|(1<<bit));
    if(cur->next[0]) dfs(cur->next[0], bit-1, val);
}

void solve(){
    cin >> Q;
    Trie* root = new Trie();
    root->insert(0, mxbit);
    while(Q--){
        int op, x; cin >> op >> x;
        if(op == 1) root->insert(x, mxbit);
        else if(op == 2) root->remove(x, mxbit);
        else{
            // root->update(x, mxbit);
            Trie *cur = root;
            ll ans = 0;
            for(int bit = mxbit; bit >= 0; bit--){
                if(!cur || !cur->cnt) break;
                int flip = (x>>bit)&1;
                if(flip){
                    if(cur->next[0] && cur->next[0]->cnt){
                        ans |= (1<<bit);
                        cur = cur->next[0];
                    }
                    else cur = cur->next[1];
                }
                else{
                    if(cur->next[1] && cur->next[1]->cnt){
                        ans |= (1<<bit);
                        cur = cur->next[1];
                    }
                    else cur = cur->next[0];
                }
            }
            cout << ans << '\n';
        }
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