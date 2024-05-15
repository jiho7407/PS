#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<ll, ll> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const ll mxnxt = 26;
ll N;

struct Trie{
    bool end;
    ll cnt;
    Trie* nxt[mxnxt];

    Trie(){
        end = false;
        cnt = 0;
        fill(nxt, nxt+mxnxt, nullptr);
    }

    ~Trie(){
        for(long long i = 0; i<mxnxt; i++){
            if(nxt[i]) delete nxt[i];
        }
    }

    void insert(const char* c){
        cnt++;
        if(*c == '\0'){
            end = true;
            return;
        }
        long long num = *c-'a';
        if(!nxt[num]) nxt[num] = new Trie;
        nxt[num]->insert(c+1);
        return;
    }

    ll count(){
        ll ret = 0;
        ret += cnt*(cnt-1)/2;
        for(long long i = 0; i<mxnxt; i++){
            if(nxt[i]) ret += nxt[i]->count();
        }
        return ret;
    }
};

void solve(){
    cin >> N;
    Trie* root = new Trie;
    rep(i, 0, N){
        string s;
        cin >> s;
        root->insert(s.c_str());
    }
    cout << root->count() - N*(N-1)/2 << '\n';
    return;
}

int main(){
    fastio();
    ll tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}