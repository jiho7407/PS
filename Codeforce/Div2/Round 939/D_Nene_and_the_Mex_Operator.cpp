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

vector<int> A;
vector<pii> query;

void build(int S, int E){
    if(S == E) return;
    build(S, E-1);
    query.push_back({S, E});
    query.push_back({S+1, E});
    build(S+1, E);
}

void solve(){
    int N; cin >> N;
    A.resize(N);
    rep(i, 0, N) cin >> A[i];

    int mx = -1, status = -1;
    rep(st, 0, 1 << (N-1)){
        int ret = 0;
        vector<int> idxs;
        rep(j, 0, N-1){
            if(st & (1 << j)){
                idxs.push_back(j);
            }
        }
        idxs.push_back(N-1);
        int last = 0;
        for(auto idx: idxs){
            // sum
            int sum = 0;
            rep(i, last, idx+1) sum += A[i];

            // ret of query
            int qret = (idx - last + 1) * (idx - last + 1);

            ret += max(sum, qret);
            last = idx+1;
        }
        if(ret > mx){
            mx = ret;
            status = st;
        }
    }

    
    vector<int> idxs;
    rep(j, 0, N-1){
        if(status & (1 << j)){
            idxs.push_back(j);
        }
    }
    idxs.push_back(N-1);
    int last = 0;
    for(auto idx: idxs){
        // sum
        int sum = 0;
        rep(i, last, idx+1) sum += A[i];

        // ret of query
        int qret = (idx - last + 1) * (idx - last + 1);
        if(sum >= qret){
            last = idx+1;
            continue;
        }

        bool flag = false;
        rep(i, last, idx+1) if(A[i] == 0) flag = true;
        rep(i, 0, 1+flag) query.push_back({last, idx});
        build(last, idx);
        query.push_back({last, idx});
        last = idx+1;
    }
    cout << mx << ' ' << query.size() << '\n';
    for(auto q: query){
        cout << q.first+1 << ' ' << q.second+1 << '\n';
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