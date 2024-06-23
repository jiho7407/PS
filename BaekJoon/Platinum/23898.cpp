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
    Trie* next[26];
    int cnt = 0;
    Trie(){
        fill(next, next+26, nullptr);
    }

    ~Trie(){
        for(int i = 0; i < 26; i++){
            if(next[i] != nullptr) delete next[i];
        }
    }

    void insert(string &s, int idx){
        cnt++;
        if(idx == s.size()){
            return;
        }
        int c = s[idx] - 'A';
        if(next[c] == nullptr) next[c] = new Trie();
        next[c]->insert(s, idx+1);
    }
};

int N, K;

int dfs(Trie* root, int depth){
    int ret = 0;
    int cnt = root->cnt;
    for(int i = 0; i<26; i++){
        if(root->next[i] != nullptr){
            ret += max(0, dfs(root->next[i], depth+1));
            cnt -= root->next[i]->cnt / K * K;
        }
    }
    ret += cnt / K * depth;
    return ret;
}

void solve(){
    cin >> N >> K;
    Trie* root = new Trie();
    rep(i, 0, N){
        string s; cin >> s;
        root->insert(s, 0);
    }
    cout << dfs(root, 0) << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        cout << "Case #" << TC << ": ";
        solve();
    }
    return 0;
}