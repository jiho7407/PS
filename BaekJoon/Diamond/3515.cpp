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

int N, M;
int dist[18][18], par[18][18];
int DP[18][1<<18], prv[18][1<<18];

vector<int> path(int a, int b){
    if(a == b) return {a};
    if(par[a][b] == -1) return {a, b};
    int k = par[a][b];
    vector<int> v1 = path(a, k);
    vector<int> v2 = path(k, b);
    v1.pop_back();
    v1.insert(v1.end(), v2.begin(), v2.end());
    return v1;
}

vector<int> get_path(int E, int mask){
    vector<int> ret;
    while(mask != 1){
        int prvv = prv[E][mask];
        vector<int> tmp = path(prvv, E);
        while(!tmp.empty()){
            ret.push_back(tmp.back());
            tmp.pop_back();
        }
        ret.pop_back();
        mask ^= (1<<E);
        E = prvv;
    }
    ret.push_back(0);
    reverse(ret.begin(), ret.end());
    return ret;
}

void solve(){
    cin >> N >> M;

    fill_n(&dist[0][0], 18*18, 1e9);
    fill_n(&par[0][0], 18*18, -1);
    rep(i, 0, M){
        int x, y, t; cin >> x >> y >> t;
        x--; y--;
        dist[x][y] = t;
        dist[y][x] = t;
    }

    rep(k, 0, N) rep(i, 0, N) rep(j, 0, N){
        if(dist[i][k] + dist[k][j] < dist[i][j]){
            dist[i][j] = dist[i][k] + dist[k][j];
            par[i][j] = k;
        }
    }

    fill_n(&DP[0][0], 18*(1<<18), 1e9);
    fill_n(&prv[0][0], 18*(1<<18), -1);
    DP[0][1] = 0;
    rep(mask, 1, 1<<N){
        rep(i, 0, N){
            if(!(mask & (1<<i))) continue;
            if(DP[i][mask] >= 1e9) continue;
            rep(j, 0, N){
                if(mask & (1<<j)) continue;
                int nxt = mask | (1<<j);
                if(DP[i][mask] + dist[i][j] < DP[j][nxt]){
                    DP[j][nxt] = DP[i][mask] + dist[i][j];
                    prv[j][nxt] = i;
                }
            }
        }
    }

    int mn = 1e9, ansA, mskA, ansB, mskB;
    rep(mask, 0, 1<<N){
        rep(a, 0, N){
            if(!(mask & (1<<a))) continue;
            if(DP[a][mask] >= 1e9) continue;

            int inv = mask ^ ((1<<N)-1);
            inv |= 1;
            rep(b, 0, N){
                if(!(inv & (1<<b))) continue;
                if((mask|inv) != (1<<N)-1) continue;
                if(DP[b][inv] >= 1e9) continue;
                
                int val = max(DP[a][mask], DP[b][inv]);
                if(val < mn){
                    mn = val;
                    ansA = a;
                    mskA = mask;
                    ansB = b;
                    mskB = inv;
                }
            }
        }
    }
    cout << mn << '\n';
    vector<int> ans = get_path(ansA, mskA);
    cout << ans.size()-1 << ' ';
    for(auto x : ans) cout << x+1 << ' ';
    cout << '\n';

    ans = get_path(ansB, mskB);
    cout << ans.size()-1 << ' ';
    for(auto x : ans) cout << x+1 << ' ';
    cout << '\n';
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