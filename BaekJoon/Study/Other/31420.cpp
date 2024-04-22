#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
string S, T;
int cnt[26][26];
int cntrr[26][26];
bool link[26][26];

bool checkr(int a[26][26]){
    for(int i = 0; i < 26; i++){
        for(int j = 0; j<26; j++){
            if(cnt[i][j] == 0 && link[i][j]) return false;
            if(cnt[i][j] != 0 && !link[i][j]) return false;
        }
    }
    return true;
}

int main(){
    fastio();
    cin >> N;
    cin >> S;
    cin >> M;
    for(int i = 0; i<26; i++){
        fill(cnt[i], cnt[i]+26, 0);
        fill(link[i], link[i]+26, 0);
    }
    for(int i = 0; i<M; i++){
        cin >> T;
        link[T[0]-'a'][T[1]-'a'] = true;
    }
    int l, r, rr;
    l = 0, r = 0, rr = 0;
    long long ans = 0, edge = 0;
    while(l < N-1){
        while(r<N-1 && edge < M){
            r++;
            if(cnt[S[r-1]-'a'][S[r]-'a']++==0) edge++;
            if(!link[S[r-1]-'a'][S[r]-'a']) break;
        }
        rr = r-1;
        while(rr < N){
            rr++;
            if(rr==N) break;
            if(!link[S[rr-1]-'a'][S[rr]-'a']) break;
        }
        // cout << l << " " << r << " " << rr << " " << ans << "\n";
        if(checkr(cnt)) ans += max(rr-r, 0);
        while(l<N-1 && r<rr){
            l++;
            if(cnt[S[l-1]-'a'][S[l]-'a']--==1) edge--;
            while(r<N-1 && edge < M){
                r++;
                if(cnt[S[r-1]-'a'][S[r]-'a']++==0) edge++;
                if(!link[S[r-1]-'a'][S[r]-'a']) break;
            }
            // cout << l << " " << r << " " << rr << " " << ans << "\n";
            if(checkr(cnt)) ans += max(rr-r, 0);
        }\
        while(l<min(N-1, rr)){
            l++;
            if(cnt[S[l-1]-'a'][S[l]-'a']--==1) edge--;
        }
    }
    cout << ans;
}