#include <bits/stdc++.h>
using namespace std;

const int mxnxt = 26;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct Trie{
    string end;
    bool amb;
    Trie* nxt[mxnxt];
    Trie* fail;

    Trie(){
        end = "";
        amb = false;
        fill(nxt, nxt+mxnxt, nullptr); // nullptr : 포인터에서 null
    }

    ~Trie(){
        for(int i = 0; i<mxnxt; i++){
            if(nxt[i]) delete nxt[i];
        }
    }

    void insert(const char*  c, int idx = 0){
        if(*c=='\0'){
            end = string(c-idx, c);
            return;
        }
        int alp = *c-'a';
        if(!nxt[alp]) nxt[alp] = new Trie;
        nxt[alp]->insert(c+1, idx+1);
        return;
    }

};

void solve(){
    int N;
    cin >> N;
    Trie *root = new Trie;
    for(int j = 0; j<N; j++){
        char Mstr[51];
        cin >> Mstr;
        root->insert(Mstr, 0);
    }
    queue<Trie*> Q;
    root -> fail = root;
    Q.push(root);
    while(!Q.empty()){
        Trie *cur = Q.front(); Q.pop();
        for(int i = 0; i<mxnxt; i++){
            Trie *goal = cur->nxt[i];
            if(!goal) continue;
            if(cur==root) goal->fail = root;
            else{
                Trie *anc = cur->fail;
                while(anc!=root && !anc->nxt[i]) anc = anc->fail;
                if(anc->nxt[i]) anc=anc->nxt[i];
                goal->fail=anc;
                // anc(ancestor) = cur.fail(), KMP느낌으로 실패함수 찾기.
            }
            if(goal->fail->end.length()>0){ // 두개 겹쳐질때
                goal->amb=true;
            } 
            Q.push(goal);
        }
    }
    int M;
    cin >> M;
    string ansstr = "";
    bool ambiguous = false;
    for(int i = 0; i<M; i++){
        string L;
        Trie *cur = root;
        cin >> L;
        for(int j = 0; j<L.length(); j++){
            int next = L[j] - 'a';
            while(cur != root && !cur->nxt[next]) cur = cur->fail;
            if(cur->nxt[next]) cur = cur->nxt[next];
            if(cur->end.length()>0){
                if(ansstr.length()>0) ambiguous = true;
                else ansstr = cur->end;
            }
            if(cur->amb) ambiguous = true;
        }
        if(ambiguous) cout << "AMBIGUOUS";
        else if(ansstr.length()>0) cout << ansstr;
        else cout << "NO";
        cout << "\n";
    }

    delete root;
}

int main(){
    fastio();
    int TC;
    cin >> TC;
    for(int i = 0; i<TC; i++){
        solve();
    }
    return 0;
}