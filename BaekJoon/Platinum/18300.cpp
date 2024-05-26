#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll M = 1'099'511'627'776;
ll S = 1'611'516'670;
ll CstartS = 516914;


ll Cstart = 350125310;
ll Clen = 182129209;

ll startcnt = 175147925;
ll cyclecnt = 91029304;

pll front[35] = {{5004364, 14370630249}, {5001652, 38312556854}, {5005667, 83248007737}, {5000724, 167560289742}, {5018889, 325792323073}, {5008935, 622741727028}, {5002371, 937685173}, {5000226, 13107744445}, {5014131, 35943646365}, {4999871, 78802032994}, {4999447, 159235062884}, {5000890, 310147760736}, {5005243, 593348380684}, {5014793, 295498034}, {4997083, 11901289737}, {5015047, 33681877906}, {4987233, 74557367833}, {4984250, 151258698876}, {5006801, 295206930517}, {5021556, 565345893787}, {4991350, 1072246754882}, {5000914, 10752858133}, {4990281, 31526697331}, {5019774, 70512631458}, {5008785, 143677078963}, {5004288, 280954761586}, {5010246, 538598461112}, {4995792, 1022070324749}, {5008168, 9655697881}, {5001165, 29466792348}, {4997572, 66642984633}, {4989189, 136417233148}, {5001550, 267368060404}, {4993504, 513107125545}, {4983477, 974225187667}};
pll cycle[18] = {{4989280, 11347508705}, {4994060, 32642538921}, {5001406, 72602179030}, {5003512, 147587596515}, {4991958, 288299158592}, {4990895, 552368730897}, {5000325, 1047889963499}, {4991381, 10220465107}, {5004337, 30528085091}, {5006063, 68635277779}, {4991531, 140147868236}, {5021042, 274358548202}, {5003897, 526208585828}, {4999034, 998852854893}, {4991392, 9149398605}, {4997277, 28517124738}, {5002467, 64866088952}, {4985167, 133077482701}};

ll calc(ll x){
    return (x + (x>>20) + 12345)%M;
}

void solve(){
    ll N; cin >> N;
    ll ans = 0;
    if(N <= Cstart){
        rep(i, 0, N/10000000){
            ans += front[i].first;
            S = front[i].second;
        }
        rep(i, N/10000000*10000000, N){
            if(S%2 == 0) ans++;
            S = calc(S);
        }
    }
    else{
        N -= Cstart;
        ans += startcnt;
        ans += cyclecnt*(N/Clen);
        N %= Clen;
        S = CstartS;
        rep(i, 0, N/10000000){
            ans += cycle[i].first;
            S = cycle[i].second;
        }
        rep(i, N/10000000*10000000, N){
            if(S%2 == 0) ans++;
            S = calc(S);
        }
    }
    cout << ans;
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