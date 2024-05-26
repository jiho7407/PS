#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<ll, ll> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct SegmentTree{
    vector<ll> tree;
    ll sz;
    void init(ll N, vector<ll>& lst){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz);
        for(ll i = 0; i < N; i++){
            tree[sz+i] = lst[i];
        }
        for(ll i = sz-1; i > 0; i--){
            tree[i] = max(tree[i<<1], tree[i<<1|1]);
        }
    }
    void update(ll i, ll x){
        ll idx = sz + i;
        tree[idx] = x;
        while(idx >>= 1){
            tree[idx] = max(tree[idx<<1], tree[idx<<1|1]);
        }
    }
    ll query(ll L, ll R){
        ll left = L + sz, right = R + sz;
        ll ret = 0;
        while(left <= right){
            if((left&1)==1) ret = max(ret, tree[left++]);
            if((right&1)==0) ret = max(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
};

ll N, T;
string S;
vector<ll> lst;
SegmentTree ST;

vector<ll> part;

void solve(){
    cin >> N >> S;
    lst.resize(N);
    rep(i, 0, N) cin >> lst[i];
    ST.init(N, lst);

    part.push_back(0);
    rep(i, 0, N-1) if(S[i] != S[i+1]) part.push_back(i+1);
    part.push_back(N);
    
    ll DP[part.size()];
    fill_n(DP, part.size(), 0);
    rep(i, 1, part.size()){
        DP[i] = DP[i-1] + ST.query(part[i-1], part[i]-1);
    }

    cin >> T;
    rep(i, 0, T){
        ll L, R; cin >> L >> R; L--; R--;
        ll Lidx = upper_bound(part.begin(), part.end(), L) - part.begin() -1;
        ll Ridx = upper_bound(part.begin(), part.end(), R) - part.begin() -1;
        if(Lidx == Ridx){
            cout << "YK 0\n";
            continue;
        }
        ll mid = DP[Ridx] - DP[Lidx+1];
        ll Lscore = ST.query(L, part[Lidx+1]-1), Rscore = ST.query(part[Ridx], R);
        char LC = S[part[Lidx]], RC = S[part[Ridx]];
        if(LC == 'Y' && RC == 'K'){
            cout << "Y ";
            cout << mid + Lscore + Rscore << '\n';
        }
        else if(LC == 'K' && RC == 'Y'){
            cout << "K ";
            cout << mid + Lscore + Rscore << '\n';
        }
        else if (LC == 'Y' && RC == 'Y'){
            if (Lscore > Rscore) cout << "Y " << mid + Lscore << '\n';
            else if(Lscore < Rscore) cout << "K " << mid + Rscore << '\n';
            else cout << "YK " << mid + Lscore << '\n';
        }
        else if (LC == 'K' && RC == 'K'){
            if (Lscore > Rscore) cout << "K " << mid + Lscore << '\n';
            else if(Lscore < Rscore) cout << "Y " << mid + Rscore << '\n';
            else cout << "YK " << mid + Lscore << '\n';
        }
    }
    return;
}

int main(){
    fastio();
    ll tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}