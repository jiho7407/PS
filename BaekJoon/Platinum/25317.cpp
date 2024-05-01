#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

set<ll> zeromaker;
ordered_set S;

int sgn(ll x){
    if(x > 0) return 1;
    if(x < 0) return -1;
    return 0;
}


void solve(){
    int Q; cin >> Q;
    int k = 1;
    while(Q--){
        ll cmd, a, b, c; cin >> cmd;
        if(cmd == 1){
            cin >> a >> b;

            // 최고차항 관리
            if(a == 0) k *= sgn(b);
            else k *= sgn(a);

            // a가 0이면 탈출
            if(a == 0) continue;

            // 정말로 0인 경우!
            if(b%a == 0) zeromaker.insert(b/a);

            // 나머지는 내림해서 이용하자.
            if((a<0 && b>0) || (a>0 && b<0)) S.insert(b/a-1);
            else S.insert(b/a);
        }
        else{
            cin >> c; c *= -1;
            if(zeromaker.find(c) != zeromaker.end()){
                cout << 0 << '\n';
                continue;
            }
            ll cnt = S.order_of_key(c);
            // cout << '\n';
            // cout << k << " " << cnt << '\n';
            ll res;
            if(cnt%2) res = k*-1;
            else res = k;
            
            if(res == 1) cout << "+\n";
            else if(res == -1) cout << "-\n";
            else cout << "0\n";
        }
    }
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