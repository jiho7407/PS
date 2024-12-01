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

int N, Q;
vector<int> A;
int lg2[100001];
int GCD_SPT[18][100000], min_SPT[18][100000];
vector<int> idxs[100000];
map<int, int> mp;

int get_GCD(int L, int R){
    int k = lg2[R-L+1];
    return __gcd(GCD_SPT[k][L], GCD_SPT[k][R-(1<<k)+1]);
}

int get_min(int L, int R){
    int k = lg2[R-L+1];
    return min(min_SPT[k][L], min_SPT[k][R-(1<<k)+1]);
}

int count_x(int L, int R, int val){
    int l = lower_bound(idxs[val].begin(), idxs[val].end(), L)-idxs[val].begin();
    int r = upper_bound(idxs[val].begin(), idxs[val].end(), R)-idxs[val].begin();
    return r-l;
}

void solve(){ 
    lg2[1] = 0;
    rep(i, 2, 100001) lg2[i] = lg2[i/2]+1;

    cin >> N;
    A.resize(N);
    rep(i, 0, N){
        cin >> A[i];
        GCD_SPT[0][i] = A[i];
        min_SPT[0][i] = A[i];
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    rep(i, 0, N) mp[A[i]] = i;
    rep(i, 0, N){
        idxs[mp[GCD_SPT[0][i]]].push_back(i);
    }

    rep(k, 1, 18) rep(i, 0, N){
        if(i+(1<<k) > N) break;
        GCD_SPT[k][i] = __gcd(GCD_SPT[k-1][i], GCD_SPT[k-1][i+(1<<(k-1))]);
        min_SPT[k][i] = min(min_SPT[k-1][i], min_SPT[k-1][i+(1<<(k-1))]);
    }

    cin >> Q;
    while(Q--){
        int L, R;
        cin >> L >> R;
        L--, R--;
        int gcd = get_GCD(L, R);
        int mn = get_min(L, R);
        // cout << gcd << ' ' << mn << '\n';
        if(gcd == mn){
            cout << R-L+1-count_x(L, R, mp[gcd]) << '\n';
        }
        else cout << R-L+1 << '\n';
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