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

struct UF_rb{
    vector<int> par, dep, savev;
    stack<pair<pii, int>> stk;
    int dsu_cnt;

    void init(int N){
        par.resize(N);
        dep.resize(N);
        dsu_cnt = N;
        savev.push_back(0);
        rep(i, 0, N) par[i] = i;
        rep(i, 0, N) dep[i] = 0;
    }

    int find(int x){
        if(par[x] == x) return x;
        return find(par[x]);
    }

    bool merge(int a, int b){
        a = find(a); b = find(b);
        if(a == b) return false;
        if(dep[a] > dep[b]) swap(a, b); // b가 더 깊게
        par[a] = b;

        if(dep[a] == dep[b]){
            dep[b]++;
            stk.push({{a, b}, 1});
        }
        else stk.push({{a, b}, 0});

        dsu_cnt--;
        savev.back()++;
        return true;
    }

    void save(){
        savev.push_back(0);
    }

    void rollback(){
        int cnt = savev.back(); savev.pop_back();
        while(cnt--){
            auto [p, d] = stk.top(); stk.pop();
            auto [a, b] = p;
            par[a] = a;
            if(d) dep[b]--;
            dsu_cnt++;
        }
    }
}UF;

int N, Q;

void solve(){
    cin >> N >> Q;
    UF.init(N);
    while(Q--){
        string op; cin >> op;
        if(op[0] == 'p'){
            UF.save();
        }
        else if(op[0] == 'u'){
            int a, b; cin >> a >> b;
            a--; b--;
            UF.merge(a, b);
            cout << UF.dsu_cnt << endl;
        }
        else{
            UF.rollback();
            cout << UF.dsu_cnt << endl;
        }
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