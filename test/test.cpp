#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int binpow(ll a, ll b, ll p) {
  ll c = 1;
  while(b) {
    if (b & 1) c = c * a % p;
    a = a * a % p, b >>= 1;
  }
  return c;
}

int main() {
  int t; cin >> t;
  while(t--) {
    int n, k, p; cin >> n >> k >> p;

    vector<ll> fac(k + 1, 1);
    for(int i = 1; i <= k; i++) fac[i] = fac[i - 1] * i % p;

    vector<ll> faci(k + 1);
    faci[k] = binpow(fac[k], p - 2, p);
    for(int i = k - 1; i >= 0; i--) faci[i] = faci[i + 1] * (i + 1) % p;

    vector<ll> pow2(n + 1, 1);
    for(int i = 1; i <= n; i++) pow2[i] = pow2[i - 1] * 2 % p;

    vector<ll> dp(k + 1, 1);
    for(int i = 1; i < n; i++) {
      vector<ll> binom(k + 1, 1);
      for(int j = 1; j <= k; j++) binom[j] = binom[j - 1] * (pow2[i] + j - 2 + p) % p;
      for(int j = 0; j <= k; j++) binom[j] = binom[j] * faci[j] % p;

      vector<ll> nxt(k + 1);
      for(int j = 0; j <= k; j++)
        for(int x = 0; x < j and j + x <= k; x++)
          nxt[j + x] = (nxt[j + x] + dp[j] * binom[x] % p) % p;

      for(int j = 1; j <= k; j++)
        nxt[j] = (nxt[j - 1] + nxt[j]) % p;
      dp.swap(nxt);

      for(int i = 0; i<=10; i++) cout << binom[i] << ' '; cout << '\n';
    }
  }
}