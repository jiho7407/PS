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

int N;
vector<string> v;
int ans = 0;
int nozero[256], mp[256];
bool used[10];

void btr(int idx, int sidx){
    if(idx == N){
        int ret = 0;
        rep(i, 0, N-1){
            int tmp = 0;
            for(auto c : v[i]) tmp = tmp*10 + mp[c];
            ret += tmp;
        }
        int tmp = 0;
        for(auto c : v[N-1]) tmp = tmp*10 + mp[c];
        if(ret == tmp) ans++;
        return;
    }
    if(sidx == v[idx].size()){
        btr(idx+1, 0);
        return;
    }

    if(mp[v[idx][0]] == 0) return;

    if(mp[v[idx][sidx]] != -1) btr(idx, sidx+1);
    else{
        rep(i, 0, 10){
            if(used[i]) continue;
            if(i == 0 && nozero[v[idx][sidx]]) continue;
            used[i] = true;
            mp[v[idx][sidx]] = i;
            btr(idx, sidx+1);
            used[i] = false;
            mp[v[idx][sidx]] = -1;
        }
    }
}

void solve(){
    cin >> N;
    rep(i, 0, N){
        string s; cin >> s;
        v.push_back(s);
        for(auto c : s) mp[c] = -1;
        nozero[s[0]] = 1;
    }

    btr(0, 0);
    cout << ans;
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