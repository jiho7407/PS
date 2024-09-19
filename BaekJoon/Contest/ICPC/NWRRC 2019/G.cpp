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

ll W, H;
int N;
vector<pll> poly;
vector<pair<ll, pll>> hor, ver;

// L <= AX <= R (mod M) 을 만족하는 가장 작은 X 찾기
ll calc(ll A, ll M, ll L, ll R){
    if(L == 0) return 0;
    A %= M;
    ll ans = 0;
    ll s1 = 1, s2 = 0;
    while(A > 0){
        if(2*A > M){
            A = M - A;
            L = M - L;
            R = M - R;
            swap(L, R);
            ans += s2;
            s1 -= s2;
            s2 *= -1;
        }
        ll ff = (L + A - 1) / A;
        if(ff * A <= R) return ans + ff*s1;
        ans += (ff-1)*s1;
        ff = (ff-1)*A;
        L -= ff;
        R -= ff;
        ll z = (M + A - 1) / A;
        s2 = s1*z - s2;
        swap(s1, s2);
        M = z*A - M;
        swap(A, M);
    }
    return -1;
}

void solve(){
    cin >> W >> H;
    cin >> N;
    rep(i, 0, N){
        ll x, y; cin >> x >> y;
        poly.push_back({x, y});
    }
    rep(i, 0, N){
        int j = (i+1)%N;
        auto [x1, y1] = poly[i];
        auto [x2, y2] = poly[j];
        if(y1 == y2){
            hor.push_back({y1, {x1, x2}});
            hor.push_back({y1, {2*W-x1, 2*W-x2}});
            hor.push_back({2*H-y1, {x1, x2}});
            hor.push_back({2*H-y1, {2*W-x1, 2*W-x2}});
        }else if(x1 == x2){
            ver.push_back({x1, {y1, y2}});
            ver.push_back({x1, {2*H-y1, 2*H-y2}});
            ver.push_back({2*W-x1, {y1, y2}});
            ver.push_back({2*W-x1, {2*H-y1, 2*H-y2}});
        }else{
            assert(false);
        }
    }

    int T; cin >> T;
    while(T--){
        ll qx, qy; cin >> qx >> qy;
        ll ans = -1;
        rep(_, 0, 2){
            for(auto [x, ys]: ver){ // 수직선들 (swap 이후엔 수평선)
                auto [y1, y2] = ys; // x = x, y1 <= y <= y2
                if(y1 > y2) swap(y1, y2);

                // t0 = (x - qx + 2*W) % (2*W)
                // y1 <= qy + t0 + 2WK <= y2 (mod 2H) 를 만족하는 가장 작은 K 찾기
                // y1 - qy - t0 <= 2WK <= y2 - qy - t0 (mod 2H)
                ll t0 = ((x - qx)%(2*W) + 2*W) % (2*W);
                ll ny1 = ((y1 - qy - t0)%(2*H) + 2*H) % (2*H);
                ll ny2 = ((y2 - qy - t0)%(2*H) + 2*H) % (2*H);
                if(ny1 > ny2){
                    if(ans == -1 || t0 < ans) ans = t0;
                }
                else{
                    ll ret = calc(2*W, 2*H, ny1, ny2);
                    if(ret != -1){
                        ll cc = ret*2*W + t0;
                        if(ans == -1 || cc < ans) ans = cc;
                    }
                }
            }
            swap(hor, ver);
            swap(W, H);
            swap(qx, qy);
        }
        if(ans == -1) cout << -1 << '\n';
        else{
            qx = (qx + ans) % (2*W);
            qy = (qy + ans) % (2*H);
            if(qx >= W) qx = 2*W - qx;
            if(qy >= H) qy = 2*H - qy;
            cout << ans << ' ' << qx << ' ' << qy << '\n';
        }
    }
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