#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
vector<tll> foods, lines;
vector<ld> intersection;

bool cmp(tll a, tll b){
    auto [a1, a2, a3] = a;
    auto [b1, b2, b3] = b;
    if(a2-a1 == b2-b1) return a1 > b1;
    return a2-a1 < b2-b1;
}

ld getInter(tll a, tll b){
    auto [a1, a2, a3] = a;
    auto [b1, b2, b3] = b;
    return (ld)(b2-a2)/(a1-b1);
}

void solve(){
    cin >> N >> M;
    rep(i, 0, N){
        int t, p; cin >> t >> p;
        foods.push_back({t, p, i+1});
    }
    sort(foods.begin(), foods.end(), cmp);
    rep(i, 0, N){
        auto [t, p, idx] = foods[i];
        tll line = {p-t, t, idx};
        if(!lines.empty() && get<0>(lines.back()) == get<0>(line)) continue;
        while(lines.size() > 1){
            ld newinter = getInter(lines.back(), line);
            if(intersection.back() < newinter) break;
            if(intersection.back() == newinter){
                if(intersection.size() >= 2 && intersection[intersection.size()-2] == newinter){
                    lines.pop_back();
                    intersection.pop_back();
                    continue;
                }
                if(get<2>(lines.back()) < get<2>(line)) break;
            }
            lines.pop_back();
            intersection.pop_back();
        }
        if(lines.size()) intersection.push_back(getInter(lines.back(), line));
        else intersection.push_back(-1e18);
        lines.push_back(line);
    }
    while(M--){
        int t, p; cin >> t >> p;
        ld prf = (ld)p/(t+p);
        int idx = lower_bound(intersection.begin(), intersection.end(), prf) - intersection.begin();
        if(idx == intersection.size()) idx = lines.size()-1;
        else if(idx > 0 && intersection[idx-1] < prf && prf < intersection[idx]) --idx;
        if(idx>0 && prf == intersection[idx] && get<2>(lines[idx-1]) < get<2>(lines[idx])) --idx;
        cout << get<2>(lines[idx]) << '\n';
    }
    // for(auto [a, b, c]: lines) cout << c << ' ';
    // cout << '\n' << '\n';
    // for(auto i: intersection) cout << i << ' ';
    // cout << '\n';
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