#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
string S;
bool L[26][26];
int cnts[26][26];

int main(){
    fastio();
    cin >> N >> S >> M;
    for(int i = 0; i < 26; i++){
        fill(cnts[i], cnts[i]+26, 0);
        fill(L[i], L[i]+26, false);
    }
    for(int i = 0; i < M; i++){
        char a, b;
        cin >> a >> b;
        L[a-'a'][b-'a'] = true;
    }

    int l = 0, r = 0, rr = 0, ans = 0, edge_size = 0;

    while(l < N){
        while(r < N && (edge_size < M || l >= r)){
            if(!L[S[r]-'a'][S[r+1]-'a']) break;
            if(cnts[S[r]-'a'][S[r+1]-'a']++ == 0) edge_size++;
            r++;
        }

        if(edge_size == M){
            rr = r;
            while(rr < N && L[S[rr]-'a'][S[rr+1]-'a']) rr++;
            ans += rr - r + 1;
        }

        if(cnts[S[l]-'a'][S[l+1]-'a']-- == 1) edge_size--;
        l++;

        while(r<rr){
            // 위랑 똑같은데 rr 재계산할 필요 X
            while(r < N && (edge_size < M || l >= r)){
                if(!L[S[r]-'a'][S[r+1]-'a']) break;
                if(cnts[S[r]-'a'][S[r+1]-'a']++ == 0) edge_size++;
                r++;
            }

            if(edge_size == M){
                ans += rr - r + 1;
            }

            if(cnts[S[l]-'a'][S[l+1]-'a']-- == 1) edge_size--;
            l++;
        }

        while(l<=rr){
            if(cnts[S[l]-'a'][S[l+1]-'a']-- == 1) edge_size--;
            l++;
        }

        if(l>r) r = l;
    }

    cout << ans;
    return 0;
}
