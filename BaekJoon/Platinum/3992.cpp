#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r) for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
vector<pii> V;
vector<pair<ld, ld>> hull;

ld gettan(pii a, pii b){
    return (ld)(b.second - a.second) / (b.first - a.first);
}

void solve(){
    cin >> N;
    rep(i, 0, N){
        int a, b;
        cin >> a >> b;
        V.push_back({a, b});
    }
    sort(V.begin(), V.end());
    tuple<ld, int, int> ans = {1e18, 0, 0};
    rep(i, 0, N){
        pair<ld, ld> up = {i+1, V[i].second};
        pair<ld, ld> down = {i, V[i].first};
        while(hull.size()>=2){
            int sz = hull.size();
            ld tan1 = gettan(hull[sz-2], down);
            ld tan2 = gettan(hull[sz-1], down);
            if(tan1 >= tan2) break;
            hull.pop_back();
        }
        hull.push_back(down);
        int ok = hull.size()-1, ng = -1;
        while(ok-ng>1){
            int mid = (ok+ng)/2;
            ld tan1 = gettan(hull[mid], up);
            ld tan2 = gettan(hull[mid+1], up);
            if(tan1 <= tan2) ok = mid;
            else ng = mid;
        }
        ld mn = gettan(hull[ok], up);
        if(mn < get<0>(ans)){
            ans = {mn, hull[ok].first, i};
        }
    }
    int a = get<1>(ans), b = get<2>(ans);
    int ansup = V[b].second - V[a].first;
    int ansdown = b-a+1;
    int g = __gcd(ansup, ansdown);
    cout << ansup/g << "/" << ansdown/g;
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