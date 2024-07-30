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

struct UnionFind{
    int par[1000], cnt[1000];
    int group;

    void init(int N){
        rep(i, 0, N){
            par[i] = i;
            cnt[i] = 1;
        }
        group = N;
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(a > b) swap(a, b);
        par[b] = a;
        cnt[a] += cnt[b];
        cnt[b] = 0;
        group--;
    }
}UF;

int N, M, K;
vector<pii> Redge, Bedge;

void solve(){
    while(1){
        Redge.clear();
        Bedge.clear();

        cin >> N >> M >> K;
        if(N + M + K == 0) return;
        rep(i, 0, M){
            char c; int a, b;
            cin >> c >> a >> b;
            a--; b--;
            if(c == 'R') Redge.push_back({a, b});
            else Bedge.push_back({a, b});
        }
        UF.init(N);
        for(auto [a, b] : Redge) UF.merge(a, b);
        for(auto [a, b] : Bedge) UF.merge(a, b);
        if(UF.group > 1){ // 스패닝트리 완성 불가
            cout << "0\n";
            continue;
        }

        UF.init(N);
        for(auto [a, b] : Redge) UF.merge(a, b);
        int mn = UF.group - 1;

        UF.init(N);
        for(auto [a, b] : Bedge) UF.merge(a, b);
        int mx = N - UF.group;
        // cout << "mn : " << mn << " mx : " << mx << '\n';

        if(mn <= K && K <= mx) cout << "1\n";
        else cout << "0\n";
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