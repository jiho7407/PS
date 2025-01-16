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

ll gcd(ll a, ll b){
    return b ? gcd(b, a%b) : a;
}

void solve(){
    ll N, M, A, B;
    cin >> N >> M >> A >> B;

    ll G = gcd(A, B);
    ll Adiv = A/G, Bdiv = B/G;
    ll Frob = Adiv*Bdiv - Adiv - Bdiv;
    vector<bool> chk(G*Frob+1, false);
    for(ll n = 0; n*A <= G*Frob; n++){
        for(ll m = 0; n*A + m*B <= G*Frob; m++){
            chk[n*A + m*B] = true;
        }
    }

    auto check = [&](ll A, ll B, ll K) -> bool{
        if(K < 0) return false;
        if(K%G != 0) return false;
        if(K > G*Frob) return true;
        return chk[K];
    };


    vector<ll> cur;
    cur.push_back(1);
    while(M--){
        ll L, R; cin >> L >> R;
        // L-20~L-1로 갈 수 있나?
        vector<ll> nxt;
        for(auto x: cur){
            rep(i, 0, 30){
                if(check(A, B, (L-i) - x)){
                    nxt.push_back(L-i);
                }
            }
        }
        nxt.erase(unique(nxt.begin(), nxt.end()), nxt.end());

        // R+1~R+20으로 갈 수 있나?
        vector<ll> nxt2;
        for(auto x: nxt){
            rep(i, A, B+1){
                if(x+i <= R) continue;
                nxt2.push_back(x+i);
            }
        }
        nxt2.erase(unique(nxt2.begin(), nxt2.end()), nxt2.end());
        cur = nxt2;
    }
    for(auto x: cur){
        if(check(A, B, N - x)){
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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