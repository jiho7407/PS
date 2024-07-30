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

// 접미사 배열
// Suffix Array

const int mxN = 1e6+1;
struct SuffixArray{
    string S;
    int N, cnt[mxN], ord[mxN], tmp[mxN], SA[mxN], LCP[mxN];

    SuffixArray(string S): S(S){
        N = S.size();
        makeSA();
        makeLCP();
    }

    void makeSA(){
        rep(i, 0, N){
            SA[i] = i;
            ord[i] = S[i];
        }
        int d = 1;
        int pnt = 1;
        while(1){
            // 기수 정렬
            // cnt: 같은 그룹의 개수, ord: 그룹 번호, SA: 정렬된 순서
            fill(cnt, cnt+mxN, 0);
            rep(i, 0, N) cnt[ord[min(i+d, N)]]++; // i+d번째 문자를 기준으로 그룹 나누기
            rep(i, 0, max(N, 255)) cnt[i+1] += cnt[i];
            for(int i = N-1; i>=0; i--) tmp[--cnt[ord[min(i+d, N)]]] = i;
            
            fill(cnt, cnt+mxN, 0);
            rep(i, 0, N) cnt[ord[i]]++; // i번째 문자를 기준으로 그룹 나누기
            rep(i, 0, max(N, 255)) cnt[i+1] += cnt[i];
            for(int i = N-1; i>=0; i--) SA[--cnt[ord[tmp[i]]]] = tmp[i];


            // 새로운 그룹 번호 부여
            if(pnt == N) break;
            pnt = 1;
            tmp[SA[0]] = 1;
            rep(i, 1, N){
                if(ord[SA[i-1]] != ord[SA[i]] || ord[SA[i-1]+d] != ord[SA[i]+d]) pnt++;
                tmp[SA[i]] = pnt;
            }
            rep(i, 0, N) ord[i] = tmp[i];
            d <<= 1;
        }
    }

    void makeLCP(){
        rep(i, 0, N) tmp[SA[i]] = i;
        for(int i=0, k=0; i<N; i++, k=max(k-1, 0)){
            if(tmp[i] == N-1) continue;
            for(int j=SA[tmp[i]+1]; S[i+k]==S[j+k]; k++);
            LCP[tmp[i]] = k;
        }
    }
};

struct Zarray{
    string S;
    int N;
    int Z[1000000];

    Zarray(string S): S(S){
        N = S.size();
        Z[0] = N;
        int l = 0, r = 0;
        rep(i, 1, N){
            if(i <= r) Z[i] = min(Z[i-l], r-i);
            while(i+Z[i] < N && S[Z[i]] == S[i+Z[i]]) Z[i]++;
            if(i>r) l = i;
            r = max(r, i+Z[i]-1);
        }
    }
};

// Segment Tree
struct SegmentTree{
    vector<int> tree;
    int sz;

    int pull(int a, int b){
        return min(a, b);
    }

    void init(int N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz);
    }
    
    void set(int i, int x){
        tree[sz+i] = x;
    }

    void build(){
        for(int i = sz-1; i > 0; i--) tree[i] = pull(tree[i<<1], tree[i<<1|1]);
    }

    void update(int i, int x){
        int idx = sz + i;
        tree[idx] += x;
        while(idx >>= 1) tree[idx] = pull(tree[idx<<1], tree[idx<<1|1]);
    }
    int query(int L, int R){
        int left = L + sz, right = R + sz;
        int ret = 1e9;
        while(left <= right){
            if((left&1)==1) ret = pull(ret, tree[left++]);
            if((right&1)==0) ret = pull(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
}ST;

int N;
vector<pair<int, int>> ans;

void solve(){
    string S; cin >> S; N = S.size();
    auto SA = new SuffixArray(S);
    ST.init(N);
    rep(i, 0, N) ST.set(i, SA->LCP[i]);
    ST.build();

    auto Zs = new Zarray(S);

    int mx = 0;
    rep(i, 0, N){
        if(SA->SA[i] == 0){
            ans.push_back({N, 1});
            break;
        }

        int sz = N - SA->SA[i];
        if(Zs->Z[SA->SA[i]] < sz) continue;

        int ok = i, ng = N;
        while(ng - ok > 1){
            int mid = (ok + ng) / 2;
            if(ST.query(ok+1, mid) >= sz) ok = mid;
            else ng = mid;
        }
        ans.push_back({sz, ok - i + 2});
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto [a, b]: ans) cout << a << ' ' << b << '\n';
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