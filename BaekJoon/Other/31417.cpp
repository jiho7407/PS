#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> pll;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
pll lst[4000];
vector<pll> sortedlst;

int ccw(const pll& a, const pll& b){
    long long c = a.first*b.second - a.second*b.first;
    if(c>0) return 1;
    if(c<0) return -1;
    return 0;
}

bool comp(const pll& a, const pll& b) {
    if(a.second<0 && b.second>0) return true;
    if(a.second>0 && b.second<0) return false;
    int c = ccw(a, b);
    if(c != 0) return c>0;
    return a.first<b.first || a.second<b.second;
}

double height(const pll& a, const pll& b){
    long long S = abs(a.first*b.second - a.second*b.first);
    return S / sqrt(max(max(a.first*a.first + a.second*a.second,
                         b.first*b.first + b.second*b.second),
                         (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second)));
}


int main(){
    fastio();
    cin >> N;
    int x, y;

    for(int i = 0; i<N; i++){
        cin >> x >> y;
        lst[i] = {x, y};
    }

    double ans;
    ans = 1000000000000;

    for(int i = 0; i<N; i++){
        sortedlst.clear();
        for(int j = 0; j<N; j++){
            if(i == j) continue;
            sortedlst.push_back({lst[j].first-lst[i].first, lst[j].second-lst[i].second});
        }
        sort(sortedlst.begin(), sortedlst.end(), comp);
        for(int j = 0; j<N-2; j++){
            ans = min(ans, height(sortedlst[j], sortedlst[j+1]));
        }
        ans = min(ans, height(sortedlst[0], sortedlst[N-2]));
    }
    cout << fixed << setprecision(10) << ans;
    return 0;
}