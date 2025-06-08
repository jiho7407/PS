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

ll N, M, A, B;
bool DP[420];

bool pos(ll x, ll y){
    ll mv = y-x;
    if(mv >= B*B) return true;
    else return DP[mv];
}

void solve(){
    cin >> N >> M >> A >> B;
    vector<ll> L(M), R(M);
    rep(i, 0, M) cin >> L[i] >> R[i];

    if(A == B){
        if((N-1)%A != 0){
            cout << "No\n";
            return;
        }
        rep(i, 0, M){
            ll ret = ((R[i]-1)/A)*A + 1;
            if(L[i] <= ret && ret <= R[i]){
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
        return;
    }

    vector<ll> S(M+1), T(M+1);
    S[0] = 1;
    rep(i, 0, M) S[i+1] = R[i]+1;
    rep(i, 0, M) T[i] = L[i]-1;
    T[M] = N;

    DP[0] = true;
    rep(i, 0, 420){
        if(!DP[i]) continue;
        rep(j, A, B+1) if(i+j < 420) DP[i+j] = true;
    }

    vector<vector<ll>> X(M+1), Y(M+1);
    X[0].push_back(1);
    set<ll> st; st.insert(1);
    rep(m, 0, M+1){
        rep(i, 0, B+1){
            ll goal = S[m] + i;
            if(goal > T[m]) break;
            bool flag = false;
            rep(j, A, B+1) if(st.count(goal-j)){
                flag = true;
                break;
            }
            if(flag){
                X[m].push_back(goal);
                st.insert(goal);
            }
        }
        rep(i, 0, B+1){
            ll goal = T[m] - i;
            if(goal < S[m]) break;
            bool flag = false;
            rep(j, A, B+1) if(st.count(goal+j)){
                flag = true;
                break;
            }
            if(!flag){
                for(auto x: X[m]) if(pos(x, goal)){
                    flag = true;
                    break;
                }
            }
            if(flag){
                Y[m].push_back(goal);
                st.insert(goal);
            }
        }
    }

    // rep(i, 0, M+1){
    //     cout << "i: " << i << endl;
    //     for(auto x: X[i]) cout << x << " "; cout << endl;
    //     for(auto y: Y[i]) cout << y << " "; cout << endl;
    // }

    if(st.count(N)) cout << "Yes\n";
    else cout << "No\n";
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