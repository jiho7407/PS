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

// 0-1 Setment Tree
// 01 세그
// 화성지도 세그
struct SegmentTree01{
    ll sz = 1;
    vector<ll> tree, cnt;

    void init(ll N){
        while(sz < N) sz <<= 1;
        tree.assign(sz<<1, 0);
        cnt.assign(sz<<1, 0);
    }

    void update(ll s, ll e, ll v){
        update(1, 0, sz-1, s, e, v);
    }

    void update(ll idx, ll ns, ll ne, ll s, ll e, ll v){
        if(e < ns || ne < s) return;
        if(s <= ns && ne <= e) tree[idx] += v;
        else{
            ll mid = (ns+ne)>>1;
            update(idx<<1, ns, mid, s, e, v);
            update(idx<<1|1, mid+1, ne, s, e, v);
        }
        // if(tree[idx] > 0) cnt[idx] = Ys[ne+1] - Ys[ns]; // 좌표압축된 경우, 업데이트는 update(y1, y2-1)
        if(tree[idx] > 0) cnt[idx] = ne-ns+1;
        else if (ns != ne) cnt[idx] = cnt[idx<<1] + cnt[idx<<1|1];
        else cnt[idx] = 0;
    }

    ll query(){
        return cnt[1];
    }
}ST;

int N, Q;
vector<int> links[100000];
map<pii, int> mp; //0: 무방향, 1: a->b, -1: b->a

int in[100000], out[100000], par[100000], oidx = 0;

void dfs(int c, int p){
    par[c] = p;
    in[c] = oidx++;
    for(int nxt : links[c]){
        if(nxt == p) continue;
        dfs(nxt, c);
    }
    out[c] = oidx-1;
}

void query1(int a, int b, int v){
    if(par[a] == b){
        ST.update(0, in[a]-1, v);
        if(out[a] != N-1) ST.update(out[a]+1, N-1, v);
    }
    else{
        ST.update(in[b], out[b], v);
    }
}

void query2(int a, int b, int v){
    if(par[a] == b){
        ST.update(in[a], out[a], v);
    }
    else{
        ST.update(0, in[b]-1, v);
        if(out[b] != N-1) ST.update(out[b]+1, N-1, v);
    }
}


void solve(){
    cin >> N;
    rep(i, 0, N-1){
        int a, b; string s;
        cin >> a >> s >> b;
        a--; b--;
        links[a].push_back(b);
        links[b].push_back(a);

        int q;
        if(s == "--") q = 0;
        else if(s == "->") q = 1;
        else q = -1;

        if(a > b){
            swap(a, b);
            q = -q;
        }

        mp[{a, b}] = q;
    }
    dfs(0, -1);

    ST.init(N);
    for(auto [p, q]: mp){
        auto [a, b] = p;
        if(q == 0) continue;
        if(q == 1) query1(a, b, 1);
        else query2(a, b, 1);
    }

    cin >> Q;
    while(Q--){
        int a, b, q; string s;
        cin >> a >> s >> b;
        a--; b--;
        if(s == "--") q = 0;
        else if(s == "->") q = 1;
        else q = -1;

        if(a > b){
            swap(a, b);
            q = -q;
        }

        if(mp[{a, b}] != 0){
            if(mp[{a, b}] == 1) query1(a, b, -1);
            else query2(a, b, -1);
        }

        if(q != 0){
            if(q == 1) query1(a, b, 1);
            else query2(a, b, 1);
        }
        mp[{a, b}] = q;

        cout << N - ST.query() << '\n';
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