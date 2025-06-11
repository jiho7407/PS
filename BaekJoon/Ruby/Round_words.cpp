/*###################################################
##           Author: Jiho Kim (wlgh7407)           ##
###################################################*/

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// #pragma GCC target("bmi2","adx","avx2")
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i < r; i++)
#define rrep(i, r, l) for(int i = r-1; i >= l; i--)
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct DynamicBitset {
    vector<ull> W;
    size_t sz;

    DynamicBitset(size_t _sz = 0) : W(( _sz + 63 ) / 64), sz(_sz) {}

    void reset() { std::fill(W.begin(), W.end(), 0); };
    void set(size_t pos) { W[pos >> 6] |= (1ULL << (pos & 63)); };
    bool get(size_t pos) const { return (W[pos >> 6] >> (pos & 63)) & 1; };
    
    size_t count() const {
        size_t c = 0;
        for(ull w : W) c += __builtin_popcountll(w);
        return c;
    }

    DynamicBitset& operator<<=(size_t d) {
        if (d >= sz) {
            reset();
            return *this;
        }

        size_t word_shift = d >> 6, bit_shift = d & 63;
        auto old = W;
        std::fill(W.begin(), W.end(), 0);

        rep(i, word_shift, old.size()) {
            ull v = old[i - word_shift] << bit_shift;
            if (bit_shift && i > word_shift) {
                v |= old[i - word_shift - 1] >> (64 - bit_shift);
            }
            W[i] = v;
        }
        if(sz & 63){
            ull mask = (1ULL << (sz & 63)) - 1;
            W.back() &= mask;
        }

        return *this;
    }

    DynamicBitset& operator|=(const DynamicBitset& o) {
        rep(i, 0, W.size()) W[i] |= o.W[i];
        return *this;
    }
    DynamicBitset& operator&=(const DynamicBitset& o) {
        rep(i, 0, W.size()) W[i] &= o.W[i];
        return *this;
    }
    DynamicBitset& operator^=(const DynamicBitset& o) {
        rep(i, 0, W.size()) W[i] ^= o.W[i];
        return *this;
    }

    DynamicBitset& operator-=(const DynamicBitset& B) {
        unsigned long long borrow = 0;
        size_t n = W.size();
        for (size_t i = 0; i < n; ++i) {
            unsigned long long wi = W[i];
            unsigned long long bi = (i < B.W.size() ? B.W[i] : 0ULL);
            unsigned long long sum = bi + borrow;
            unsigned long long res = wi - sum;
            borrow = (wi < sum) ? 1 : 0;
            W[i] = res;
        }
        return *this;
    }

    DynamicBitset operator<<(size_t d) const { return DynamicBitset(*this) <<= d; }
    DynamicBitset operator|(const DynamicBitset& o) const { return DynamicBitset(*this) |= o; }
    DynamicBitset operator&(const DynamicBitset& o) const { return DynamicBitset(*this) &= o; }
    DynamicBitset operator^(const DynamicBitset& o) const { return DynamicBitset(*this) ^= o; }
    DynamicBitset operator-(const DynamicBitset& o) const { return DynamicBitset(*this) -= o; }
};

void solve(){
    string s, t; cin >> s >> t;
    if(s.size() > t.size()) swap(s, t);
    int ans = 0;

    int n = s.size(), m = t.size();
    vector<DynamicBitset> alp(26, DynamicBitset(m));
    rep(i, 0, m) alp[t[i]-'a'].set(i);

    DynamicBitset DP(m), x(m);
    rep(offset, 0, n){
        DP.reset();
        int idx = offset;
        rep(i, 0, n){
            char c = s[idx];
            if(++idx == n) idx = 0;
            x = alp[c - 'a'] | DP;
            DP <<= 1;
            DP.set(0);
            DP = x & (x ^ (x - DP));
        }
        ans = max(ans, (int)DP.count());
    }
    reverse(s.begin(), s.end());
    rep(offset, 0, n){
        DP.reset();
        int idx = offset;
        rep(i, 0, n){
            char c = s[idx];
            if(++idx == n) idx = 0;
            x = alp[c - 'a'] | DP;
            DP <<= 1;
            DP.set(0);
            DP = x & (x ^ (x - DP));
        }
        ans = max(ans, (int)DP.count());
    }
    cout << ans << endl;
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