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

int M, N;

bool cmp(pii a, pii b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

struct DynamicUF{
    int N;
    vector<int> par;

    void init(int n){
        N = n;
        par.resize(N);
        rep(i, 0, N) par[i] = i;
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
        par[a] = b;
    }
}UF;

void solve(){ 
    cin >> M >> N;
    vector<pii> v;
    rep(i, 0, N){
        int s, e; cin >> s >> e;
        if(s <= e){
            v.push_back({s, e});
            v.push_back({s+M, e+M});
        }
        else{
            v.push_back({s, e+M});
        }
    }
    if(N > M){
        cout << "NO\n";
        return;
    }
    sort(v.begin(), v.end(), cmp);
    vector<int> xs;
    for(auto [s, e]: v) xs.push_back(s);
    xs.push_back(2*M);
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    UF.init(xs.size());
    vector<int> cnt(xs.size()), cnt2(xs.size());
    rep(i, 0, xs.size() - 1) cnt[i] = xs[i+1] - xs[i];
    rep(i, 0, xs.size() - 1) cnt2[i] = 0;
    map<int, int> mp;
    rep(i, 0, xs.size()) mp[xs[i]] = i;

    for(auto [s, e]: v){
        s = mp[s];
        if(xs[UF.find(s)]+cnt2[UF.find(s)] > e){
            cout << "NO\n";
            return;
        }
        cnt2[UF.find(s)]++;
        if(--cnt[UF.find(s)] == 0) UF.merge(UF.find(s), UF.find(s)+1);
    }
    cout << "YES\n";
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}