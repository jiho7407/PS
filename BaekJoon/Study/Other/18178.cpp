#include <bits/stdc++.h>
using namespace std;

const long long mxnxt = 26;
const long long mxnod = 101;
const long long mod = 1'000'000'007;
long long idx=0;
long long mat[101][101];
long long ans[mxnod][mxnod];

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct Trie{
    bool end;
    long long trieidx;
    Trie* fail;
    Trie* nxt[mxnxt];

    Trie(){
        end = false;
        fill(nxt, nxt+mxnxt, nullptr);
    }

    ~Trie(){
        for(long long i = 0; i<mxnxt; i++){
            if(nxt[i]) delete nxt[i];
        }
    }

    void insert(const char* c){
        if(*c == '\0'){
            end = true;
            return;
        }
        long long num = *c-'a';
        if(!nxt[num]) nxt[num] = new Trie;
        nxt[num]->insert(c+1);
        return;
    }
};

auto matcalc(long long mat1[mxnod][mxnod], long long mat2[mxnod][mxnod]){
    long long _tmpmat[mxnod][mxnod];
    for(long long i = 0; i<mxnod; i++){
        for(long long j = 0; j<mxnod; j++){
            _tmpmat[i][j] = 0;
            for(long long k = 0; k<mxnod; k++){
                _tmpmat[i][j] += mat1[i][k]*mat2[k][j];
                _tmpmat[i][j] %= mod;
            }
        }
    }
    for(long long i = 0; i<mxnod; i++){
        for(long long j = 0; j<mxnod; j++){
            mat1[i][j] = _tmpmat[i][j];
        }
    }
}

void matpow(long long _mat[mxnod][mxnod], long long _B){
    for(long long i = 0; i<mxnod; i++){
        fill(ans[i], ans[i]+mxnod, 0);
        ans[i][i] = 1;
    }
    while(_B>0){
        if(_B%2) matcalc(ans, mat);
        matcalc(mat, mat);
        _B /= 2;
    }
}

void printmat(long long _mat[mxnod][mxnod]){
    for(long long i = 0; i<idx; i++){
        for(long long j = 0; j<idx; j++){
            cout << _mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    fastio();
    long long N, q;
    cin >> N >> q;

    Trie *root = new Trie;
    for(long long i = 0; i<q; i++){
        long long M;
        char T[101];
        cin >> M >> T;
        root->insert(T);
    }
    queue<Trie*> Q;
    root->fail = root;
    Q.push(root);
    while(!Q.empty()){
        Trie *cur = Q.front(); Q.pop();
        cur->trieidx = idx++;
        for(long long i = 0; i<mxnxt; i++){
            Trie *goal = cur->nxt[i];
            if(!goal) continue;
            if(cur==root) goal->fail = root;
            else{
                Trie *anc = cur->fail;
                while(anc!=root && !anc->nxt[i]) anc = anc->fail;
                if(anc->nxt[i]) anc=anc->nxt[i];
                goal->fail=anc;
            }
            if(goal->fail->end) goal->end=true;
            Q.push(goal);
        }
    }
    Q.push(root);
    for(long long i = 0; i<101; i++){
        fill(mat[i], mat[i]+101, 0);
    }
    while(!Q.empty()){
        Trie *cur = Q.front(); Q.pop();
        for(long long i = 0; i<mxnxt; i++){
            Trie *goal = cur->nxt[i];
            if(!goal){
                Trie *anc = cur->fail;
                while(anc!=root && !anc->nxt[i]) anc = anc->fail;
                if(anc->nxt[i]) anc=anc->nxt[i];
                if(anc->end) continue;
                mat[cur->trieidx][anc->trieidx] += 1;
            }
            else if(goal->end){
                continue;
            }
            else{
                mat[cur->trieidx][goal->trieidx] += 1;
                Q.push(goal);
            }
        }
    }
    matpow(mat, N);
    long long realans=0;
    for(long long i = 0; i<idx; i++){
        realans += ans[0][i];
        realans %= mod;
    }
    cout << realans;
    return 0;
}