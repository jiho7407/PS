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

void solve(){
    int N, M; cin >> N >> M;
    map<string, tuple<ll, ll, ll>> car;
    rep(i, 0, N){
        string name; ll p, q, k;
        cin >> name >> p >> q >> k;
        car[name] = {p, q, k}; // 원가, 초기대여비용, 1km당 추가비용
    }
    map<string, tuple<bool, ll, string>> man; // 대여중인지 유무, 비용, 차 이름
    while(M--){
        int time; cin >> time;
        string name; char op; cin >> name >> op;
        if(man.find(name) == man.end()){ man[name] = {false, 0, ""}; }

        auto [status, cost, rent] = man[name];
        if(op == 'p'){
            string carname; cin >> carname;
            if(cost == -1) continue;
            if(status) cost = -1; // 불가능
            else{
                auto [p, q, k] = car[carname];
                cost += q;
            }
            man[name] = {true, cost, carname};
        }
        else if(op == 'r'){
            ll dist; cin >> dist;
            if(cost == -1) continue;
            if(!status) cost = -1; // 불가능
            else{
                auto [p, q, k] = car[rent];
                cost += dist * k;
            }
            man[name] = {false, cost, ""};
        }
        else{
            ll s; cin >> s;
            if(cost == -1) continue;
            if(!status) cost = -1; // 불가능
            else{
                auto [p, q, k] = car[rent];
                ll cost2 = p*s;
                if(p*s%100) cost2 = cost2/100 + 1;
                else cost2 = cost2/100;
                cost += cost2;
            }
            man[name] = {true, cost, rent};
        }
    }
    vector<pair<string, ll>> ans;
    for(auto [k, v]: man){
        auto [status, cost, rent] = v;
        if(status) cost = -1;
        ans.push_back({k, cost});
    }
    sort(ans.begin(), ans.end());
    for(auto [name, cost]: ans){
        cout << name << " ";
        if(cost == -1) cout << "INCONSISTENT\n";
        else cout << cost << "\n";
    }
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}