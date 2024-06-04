#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const ll INF = 1e18;
struct LiChaoTree{
    // 구조체 정의
    struct Line{
        ll a, b;
        ll func(ll x){ return a*x + b; }
    };
    Line base = {0, INF};
    struct Node{
        int l, r;
        ll s, e;
        Line line;
    };

    // 메인 트리
    vector<Node> tree;

    // 구간의 범위를 입력받아 초기화
    void init(ll s, ll e){
        tree.push_back({-1, -1, s, e, base});
    }

    void update(Line nl){ update(0, nl); }
    void update(int node, Line nl){
        ll s = tree[node].s, e = tree[node].e;
        ll m = (s+e)>>1;

        // 구간의 왼쪽 끝을 기준으로 high low 결정
        Line low = tree[node].line, high = nl;
        if(low.func(s) > high.func(s)) swap(low, high);

        // 구간의 오른쪽 끝을 기준으로 전체적으로 높은지 판단
        if(low.func(e) <= high.func(e)){ tree[node].line = low; return; }

        // 아니라면 중간값을 이용해 더 많은곳에서 높은 선 판단
        if(low.func(m) <= high.func(m)){
            tree[node].line = low;
            if(tree[node].r == -1){
                tree[node].r = tree.size();
                tree.push_back({-1, -1, m+1, e, {0, INF}});
            }
            update(tree[node].r, high);
        }
        else{
            tree[node].line = high;
            if(tree[node].l == -1){
                tree[node].l = tree.size();
                tree.push_back({-1, -1, s, m, {0, INF}});
            }
            update(tree[node].l, low);
        }
    }
    
    ll query(ll x){ return query(0, x); }
    ll query(int node, ll x){
        if (node == -1) return INF;
        ll s = tree[node].s, e = tree[node].e;
        ll m = (s+e)>>1;
        if (x<=m) return min(tree[node].line.func(x), query(tree[node].l, x));
        else return min(tree[node].line.func(x), query(tree[node].r, x));
    }
}LiCT;

int N;
vector<pll> land, use;

bool cmp(pll a, pll b){
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

void solve(){
    cin >> N;
    rep(i, 0, N){
        ll w, h; cin >> w >> h;
        land.push_back({w, h});
    }
    sort(land.begin(), land.end(), cmp);
    use.push_back(land[0]);
    rep(i, 1, N){
        if(use.back().second >= land[i].second) continue;
        use.push_back(land[i]);
    }
    LiCT.init(0, 1e6);
    ll dp = 0;
    rep(i, 0, use.size()){
        LiCT.update({use[i].first, dp});
        dp = LiCT.query(use[i].second);
    }
    cout << dp << "\n";
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}