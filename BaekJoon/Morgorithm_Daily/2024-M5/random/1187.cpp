#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void calc(int N, vector<pair<int, vector<int>>> arr){
    if(N == 1){
        for(auto x: arr[0].second){
            cout << x << " ";
        }
        return;
    }
    vector<pair<int, vector<int>>> odd, even, newarr;
    rep(i, 0, 2*N-1){
        if(arr[i].first % 2){
            odd.push_back(arr[i]);
        }
        else{
            even.push_back(arr[i]);
        }
    }
    for(int i = 1; i<odd.size(); i+=2){
        newarr.push_back({(odd[i].first+odd[i-1].first)/2, {odd[i].second.begin(), odd[i].second.end()}});
        for(auto x: odd[i-1].second){
            newarr.back().second.push_back(x);
        }
    }
    for(int i = 1; i<even.size(); i+=2){
        newarr.push_back({(even[i].first+even[i-1].first)/2, {even[i].second.begin(), even[i].second.end()}});
        for(auto x: even[i-1].second){
            newarr.back().second.push_back(x);
        }
    }
    calc(N/2, newarr);
    return;
}


void solve(){
    int N; cin>>N;
    vector<pair<int, vector<int>>> arr;
    rep(i, 0, 2*N-1){
        int x; cin >> x;
        arr.push_back({x, {x}});
    }
    calc(N, arr);
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