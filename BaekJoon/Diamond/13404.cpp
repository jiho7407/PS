#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

map<string, int> mp;
pii goal;
int sidx = 0;
int N, M;
vector<pii> document[1000];
bool used[1000];

string S1, S2;
set<pii> st;

void solve(){
    cin >> S1 >> S2;
    mp[S1] = sidx++;
    mp[S2] = sidx++;
    goal = {mp[S1], mp[S2]};
    cin >> N;
    rep(i, 0, N){
        cin >> M;
        while(M--){
            string S1, S2; cin >> S1 >> S2;
            if(mp.find(S1) == mp.end()) mp[S1] = sidx++;
            if(mp.find(S2) == mp.end()) mp[S2] = sidx++;
            document[i].push_back({mp[S1], mp[S2]});
        }
    }

    st.insert(goal);
    while(1){
        bool flag = false;
        for(int i = 0; i < N; i++){
            if(used[i]) continue;

            // 이 문서를 결정지을 필요가 있다면
            bool flag2 = false;
            for(auto [a, b]: document[i]){
                if(st.find({a, b}) != st.end()){
                    flag = true;
                    flag2 = true;
                    break;
                }
            }


            // 문서에 적힌 내용대로 옮기기
            if(flag2){
                for(auto [a, b]: document[i]){
                    if(st.find({a, b}) == st.end()){
                        vector<int> anc, des;
                        anc.push_back(a);
                        des.push_back(b);
                        for(auto [c, d]: st) if(d == a) anc.push_back(c);
                        for(auto [c, d]: st) if(c == b) des.push_back(d);
                        for(auto c: anc) for(auto d: des) st.insert({c, d});
                    }
                }
                used[i] = true;
            }
        }
        if(!flag) break;
    }
    bool ok = true;
    rep(i, 0, sidx) rep(j, 0, sidx){
        if(i == j) continue;
        if(st.find({i, j}) != st.end() && st.find({j, i}) != st.end()){
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No");
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