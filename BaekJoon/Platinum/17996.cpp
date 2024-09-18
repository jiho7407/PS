#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

double PI = 3.14159265358979323846;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
map<double, double> mp;
vector<double> ans;

void solve(){
    cin >> N;
    ans.push_back(0);
    mp[0] = mp[2*PI] = 0;
    rep(i, 0, N){
        double T, S, A;
        cin >> T >> S >> A;

        if(S == 0){
            ans[0] += T;
            continue;
        }

        if(T >= PI*S){
            ans[0] += T - S*min(A, 2*PI-A);
            if(A <= PI){
                mp[0] += S;
                mp[A] -= 2*S;
                mp[A+PI] += 2*S;
                mp[2*PI] -= S;
            }
            else{
                mp[0] -= S;
                mp[A-PI] += 2*S;
                mp[A] -= 2*S;
                mp[2*PI] += S;
            }
            continue;
        }

        // 기울기 양수 부분
        double start = A - (T/S);
        if(start < 0){
            ans[0] += T - S*A;
            mp[0] += S;
            mp[start + 2*PI] += S;
        }
        else{
            mp[start] += S;
        }

        // 꺾이는 부분
        mp[A] -= 2*S;

        // 기울기 음수 부분
        double end = A + (T/S);
        if(end < 2*PI){
            mp[end] += S;
        }
        else{
            ans[0] += T - S*(2*PI - A);
            mp[0] -= S;
            mp[end - 2*PI] += S;
            mp[2*PI] += S;
        }
    }

    for(auto it = mp.begin(); it !=  mp.end(); it++){
        if(it == mp.begin()) continue;
        it->second += prev(it)->second;
    }

    for(auto it = mp.begin(); it != mp.end(); it++){
        if(next(it) == mp.end()) break;
        ans.push_back(ans.back() + it->second * (next(it)->first - it->first));
    }

    double mx = 0;
    for(auto x : ans){
        mx = max(mx, x);
    }
    cout << fixed << setprecision(6);
    cout << mx << '\n';

    // for(auto x : ans){
    //     cout << x << ' ';
    // }
    // cout << '\n';
    // for(auto [k, v]: mp){
    //     cout << k << ' ' << v << '\n';
    // }
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