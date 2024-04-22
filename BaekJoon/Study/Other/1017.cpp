#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mx = 1010;
bool isprime[2*mx];
int A[mx], B[mx];
int AM[mx], BM[mx];
vector<int> Alink[mx];
bool Avisit[mx];
int N;


void eratos(){
    fill(isprime, isprime+2*mx, true);
    isprime[1] = false;
    for(int i = 2; i<2*mx; i++){
        if(!isprime[i]) continue;
        for(int j = i*i; j<2*mx; j += i){
            isprime[j] = false;
        }
    }
}

bool dfs(int a){
    if(a == 0 || Avisit[a]) return false;
    
    Avisit[a] = true;

    for(auto b: Alink[a]){
        if(BM[b] == -1 || dfs(BM[b])){
            AM[a] = b;
            BM[b] = a;
            return true;
        }
    }
    return false;
}

int main(){
    fastio();
    eratos();
    cin >> N;
    int first;
    int Acnt=0, Bcnt=0;
    for(int i = 0; i<N; i++){
        int num;
        cin >> num;
        if(num%2) A[Acnt++] = num;
        else B[Bcnt++] = num;
        if(i==0) first = num;
    }
    if(first%2==0){
        swap(A, B);
        swap(Acnt, Bcnt);
    }
    for(int i = 0; i<Acnt; i++){
        for(int j = 0; j<Bcnt; j++){
            if(isprime[A[i]+B[j]]) Alink[i].push_back(j);
        }
    }
    vector<int> ans;
    for(auto g: Alink[0]){
        if(!isprime[A[0]+B[g]]) continue;
        fill(AM, AM+Acnt, -1);
        fill(BM, BM+Bcnt, -1);
        int match = 1;
        AM[0] = g, BM[g] = 0;
        for(int a = 1; a<Acnt; a++){
            fill(Avisit, Avisit+Acnt, false);
            if(dfs(a)) match += 1;
        }

        if(match == (N+1)/2) ans.push_back(B[g]);
    }
    sort(ans.begin(), ans.end());
    for(auto g: ans) cout << g << " ";
    if(ans.size() == 0) cout << -1;
    return 0;
}