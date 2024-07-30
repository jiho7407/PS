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

struct Trie{
    Trie *nxt[26];
    Trie *fail;
    bool exist;
    Trie(){
        rep(i, 0, 26) nxt[i] = nullptr;
        fail = nullptr;
        exist = false;
    }
    ~Trie(){
        rep(i, 0, 26) if(nxt[i]) delete nxt[i];
    }

    void insert(string &S, int idx){
        if(idx == S.size()){
            exist = true;
            return;
        }
        int c = S[idx] - 'a';
        if(!nxt[c]) nxt[c] = new Trie();
        nxt[c]->insert(S, idx+1);
    }
}root;

int N, Q;

void solve(){
    cin >> N;
    rep(i, 0, N){
        string S; cin >> S;
        root.insert(S, 0);
    }

    queue<Trie*> q;
    root.fail = &root;
    q.push(&root);
    while(!q.empty()){
        Trie *cur = q.front(); q.pop();
        rep(i, 0, 26){
            Trie *nxt = cur->nxt[i];
            if(!nxt) continue;
            if(cur == &root) nxt->fail = &root;
            else{
                Trie *tmp = cur->fail;
                while(tmp != &root && !tmp->nxt[i]) tmp = tmp->fail;
                if(tmp->nxt[i]) tmp = tmp->nxt[i];
                nxt->fail = tmp;
            }
            if(nxt->fail->exist) nxt->exist = true;
            q.push(nxt);
        }
    }

    cin >> Q;
    while(Q--){
        string T; cin >> T;
        Trie *cur = &root;
        bool flag = false;
        for(auto c: T){
            int idx = c - 'a';
            while(cur != &root && !cur->nxt[idx]) cur = cur->fail;
            if(cur->nxt[idx]) cur = cur->nxt[idx];
            if(cur->exist){
                flag = true;
                break;
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
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