#include <bits/stdc++.h>
using namespace std;

const int mxnxt = 10;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct Trie{
    bool end;
    bool child;
    Trie* nxt[mxnxt];

    Trie(){
        end = false;
        child = false;
        fill(nxt, nxt+mxnxt, nullptr); // nullptr : 포인터에서 null
    }

    ~Trie(){
        for(int i = 0; i<mxnxt; i++){
            if(nxt[i]) delete nxt[i];
        }
    }

    bool insert(const char* c){ // true : 겹치는거 있음
        if(*c == '\0'){ // \0 : 문자열에서 null
            end = true;
            if(child) return true;
            return false;
        }
        int num = *c-'0';
        if(!nxt[num]) nxt[num] = new Trie;
        child = true;
        if(end==true) return true;
        return nxt[num]->insert(c+1);
    }
};

int main(){
    fastio();
    int TC;
    cin >> TC;
    for(int i = 0; i<TC; i++){
        int N;
        cin >> N;
        Trie *trie = new Trie;
        bool result = false;
        for(int j = 0; j<N; j++){
            char nums[11];
            cin >> nums;
            result = result || trie->insert(nums);
            if(result) break;
        }
        if(result){
            cout << "NO" << "\n";
        }
        else{
            cout << "YES" << "\n";
        }
        delete trie;
    }
}