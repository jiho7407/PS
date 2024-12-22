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

struct sumseg{
    int N;
    vector<ll> a,seg;
    void init(int n){
        N=n;
        a.resize(N);
        seg.resize(2*N);
        rep(i, 0, 2*N) seg[i]=0;
    }
    void update(int i, ll val){
        a[i] = val;
        seg[i+N]=val;
        int p = (i+N)>>1;
        while(p>0){
            seg[p] = seg[p<<1]+seg[p<<1|1];
            p>>=1;
        }
    }
    ll query(int l, int r){
        if (l>r){return 0LL;}
        ll ret=0;
        int lp,rp;
        lp = l+N; rp=r+N+1;
        while(lp<rp){
            if (lp&1){ret+=seg[lp++];}
            if (rp&1){ret+=seg[--rp];}
            lp>>=1; rp>>=1;
        }
        return ret;
    }

    int query2(int l, int r){
        if (l>r){return 1e9;}
        if(query(l, r) == 0) return 1e9;
        int ok = r, ng = l-1;
        while(ok - ng > 1){
            int mid = (ok + ng) / 2;
            if(query(l, mid) > 0) ok = mid;
            else ng = mid;
        }
        return ok;
    }
}ST;

struct HLD{
    int N,cnt;
    vector<int> h,par,pos,head,heavy;
    vector<vector<int>> g;

    vector<int> rev;
    HLD(int n){
        N=n; cnt=0;
        h.resize(n,-1);
        par.resize(n,-1);
        pos.resize(n,-1);
        head.resize(n,-1);
        heavy.resize(n,-1);
        g.resize(n);
        rev.resize(n, -1);
    }
    void init(int r){
        h[r]=0;
        dfs(r);
        decompose(r,r);
    }
    int dfs(int u){
        int ret = 1;
        int m,c; m=c=-1;
        for (int& v:g[u]){
            if (par[u]==v){continue;}
            h[v]=h[u]+1;
            par[v]=u;
            int sub = dfs(v);
            ret+=sub;
            if (sub>m){
                m=sub; heavy[u]=v;
            }
        }
        return ret;
    }
    void decompose(int u, int h){
        pos[u]=cnt; rev[cnt] = u;
        ++cnt; head[u]=h;
        if (heavy[u]!=-1){
            decompose(heavy[u],h);
        }
        for (int& v:g[u]){
            if (par[u]==v){continue;}
            if (v==heavy[u]){continue;}
            decompose(v,v);
        }
    }
    int query(int u, int v){
        int ret = 1e9;
        while(head[u]!=head[v]){
            if (h[head[u]]>h[head[v]]){swap(u,v);}
            int tmp = ST.query2(pos[head[v]], pos[v]);
            if(tmp != 1e9) ret = rev[tmp];
            v = par[head[v]];
        }
        if (h[u]>h[v]){swap(u,v);}
        int tmp = ST.query2(pos[u], pos[v]);
        if(tmp != 1e9) ret = rev[tmp];
        if(ret == 1e9) return -1;
        return ret+1;
    }
};

void solve(){
    int N; cin >> N;
    ST.init(N+10);
    HLD hld(N+10);
    rep(i, 0, N-1){
        int u,v; cin >> u >> v;
        u--; v--;
        hld.g[u].push_back(v);
        hld.g[v].push_back(u);
    }
    hld.init(0);
    int Q; cin >> Q;
    while(Q--){
        int op, v; cin >> op >> v; v--;
        if(op == 1){
            int pos = hld.pos[v];
            if(ST.a[pos] == 0) ST.update(pos, 1);
            else ST.update(pos, 0);
        }
        else{
            cout << hld.query(0, v) << '\n';
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