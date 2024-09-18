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

int N;
string S;

ll DP[14][137][137];

ll btr1(int idx, int cursum, int goal){
    if(idx == N){
        if(cursum == goal) return 1;
        return 0;
    }
    ll &ret = DP[idx][cursum][goal];
    if(ret != -1) return ret;
    ret = 0;
    rep(i, 0, min(9, goal-cursum)+1){
        ret += btr1(idx+1, cursum+i, goal);
    }
    return ret;
}

vector<ll> digits;
map<ll, ll> cnt;

ll btr3(int idx){
    ll ret = 0;
    for(auto [k, v]: cnt){
        if(v == 0) continue;
        if(k < S[idx]-'0'){
            ll tmp = 1;
            rep(i, 1, N-idx) tmp *= i;
            map<ll, ll> tmpcnt = cnt;
            tmpcnt[k]--;
            for(auto [k, v]: tmpcnt) rep(i, 1, v+1) tmp /= i;
            ret += tmp;
        }
        else if(k == S[idx]-'0'){
            cnt[k]--;
            ret += btr3(idx+1);
            cnt[k]++;
        }
    }
    return ret;
}

ll btr2(ll idx, ll cursum, ll curprod, ll goalsum, ll goalprod){
    if(cursum > goalsum) return 0;
    if(curprod > goalprod) return 0;

    if(idx == N){
        if(cursum != goalsum) return 0;
        // Case 2
        if(curprod < goalprod){
            ll ret = 1;
            rep(i, 1, N+1) ret *= i;
            map<ll, ll> cnt;
            for(auto d: digits) cnt[d]++;
            for(auto [k, v]: cnt) rep(i, 1, v+1) ret /= i;
            return ret;
        }
        // Case 3
        if(curprod == goalprod){
            cnt.clear();
            for(auto d: digits) cnt[d]++;
            ll ret = btr3(0);
            return ret;
        }
    }

    ll ret = 0;
    rep(i, (digits.empty()) ? 0 : digits.back(), 10){
        digits.push_back(i);
        ret += btr2(idx+1, cursum+i, curprod*(i+1), goalsum, goalprod);
        digits.pop_back();
    }
    return ret;
}


void solve(){
    cin >> S;
    N = S.size();

    ll ans = 0;

    // Case 1: sum(s1) < sum(s2)
    ll sum = 0;
    for(auto c: S) sum += c - '0';
    rep(i, 0, sum){
        fill_n(&DP[0][0][0], 14*137*137, -1);
        ans += btr1(0, 0, i);
    }

    // Case 2: sum(s1) == sum(s2), prod(s1) < prod(s2)
    // Case 3: sum(s1) == sum(s2), prod(s1) == prod(s2), int(s1) < int(s2)
    ll prod = 1;
    for(auto c: S) prod *= (ll)((c - '0') + 1);
    ans += btr2(0, 0, 1, sum, prod);

    cout << ans << '\n';
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