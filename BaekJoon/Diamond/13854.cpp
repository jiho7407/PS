#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
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

// FFT
const double PI = acos(-1);
typedef complex<double> cpd;

//비재귀 FFT https://blog.myungwoo.kr/54, https://blog.naver.com/kks227/221633584963 참조.. 
void FFT(vector<cpd> &A, bool ivt){
    int N = A.size();

    // 비트 반전순서로 재배치 -> 띄엄띄엄 참조하지 않아 더 빨라짐!
    int j = 0;
    for(int i = 1; i < N; i++){
        int bit = N >> 1;
        while(j>=bit){
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if (i < j) swap(A[i], A[j]);
    }

    // FFT 수행
    for(int len = 2; len<= N; len <<= 1){
        double th = 2*PI/len;
        if(ivt) th *= -1;
        cpd w_unit(cos(th), sin(th));
        for(int i = 0; i<N; i+=len){
            cpd w = cpd(1, 0);
            for(int j = 0; j<len/2; j++){
                cpd u = A[i+j]; // 짝수부
                cpd v = A[i+j+len/2]*w; // 홀수부
                A[i+j] = u+v;
                A[i+j+len/2] = u-v;
                w *= w_unit;
                // 0-1 2-3 4-5 6-7 / 0-2 1-3 4-6 5-7 / 0-4 1-5 2-6 3-7...
                // 원래 숫자는 1-5 3-7 2-6 4-8 / ...
            }
        }
    }

    if(ivt){
        for(int i = 0; i<N; i++) A[i] /= N;
    }
}

void mul(const vector<int> &A, const vector<int> &B, vector<int> &ret){
    vector<cpd> AA(A.begin(), A.end()), BB(B.begin(), B.end());
    int N = 1;
    while(N < AA.size() + BB.size()) N <<= 1;
    AA.resize(N); BB.resize(N);
    FFT(AA, false); FFT(BB, false);
    for(int i = 0; i<N; i++) AA[i] *= BB[i];
    FFT(AA, true);
    ret.resize(N);
    rep(i, 0, N){
        ret[i] = round(AA[i].real());
        // if(ret[i]) ret[i] = 1;
    }
}

ll N;
vector<int> links[100000];
int deg[100000];
bool visited[100000];

bool isPrime[100001];
vector<int> primes;

int getSz(int c, int p){
    deg[c] = 1;
    for(auto nxt: links[c]){
        if(nxt == p || visited[nxt]) continue;
        deg[c] += getSz(nxt, c);
    }
    return deg[c];
}

int getCt(int c, int p, int sz){
    for(auto nxt: links[c]){
        if(nxt == p || visited[nxt]) continue;
        if(deg[nxt] > sz>>1) return getCt(nxt, c, sz);
    }
    return c;
}

int mxd = 0;
vector<int> tmp1, tmp2, tmp3;

void dfs(int c, int p, int d){
    mxd = max(mxd, d);
    tmp2[d]++;
    for(auto nxt: links[c]){
        if(nxt == p || visited[nxt]) continue;
        dfs(nxt, c, d+1);
    }
}

ll calc(){
    int ret = 0;
    mul(tmp1, tmp2, tmp3);
    for(auto p: primes){
        if(p >= tmp3.size()) break;
        ret += tmp3[p];
    }
    return ret;
}

ll DnC(int c){
    int sz = getSz(c, -1);
    int ct = getCt(c, -1, sz);
    visited[ct] = true;

    tmp1.clear();
    tmp1.resize(1);
    tmp1[0] = 1;

    sort(links[ct].begin(), links[ct].end(), [&](int a, int b){return deg[a] < deg[b];});

    ll ret = 0;
    for(auto nxt: links[ct]){
        if(visited[nxt]) continue;
        mxd = 0;
        tmp2.clear();
        tmp2.resize(deg[nxt]+1, 0);
        dfs(nxt, ct, 1);
        tmp2.resize(mxd+1);
        ret += calc();
        if(tmp1.size() < mxd+1) tmp1.resize(mxd+1);
        rep(i, 0, mxd+1) tmp1[i] += tmp2[i];
    }

    for(auto nxt: links[ct]){
        if(visited[nxt]) continue;
        ret += DnC(nxt);
    }

    return ret;
}

void solve(){
    cin >> N;
    rep(i, 0, N-1){
        int a, b; cin >> a >> b; a--; b--;
        links[a].push_back(b);
        links[b].push_back(a);
    }
    fill(isPrime, isPrime+N, true);
    isPrime[0] = isPrime[1] = false;
    rep(i, 2, N){
        if(!isPrime[i]) continue;
        for(int j = i*2; j <= N; j += i){
            isPrime[j] = false;
        }
    }
    rep(i, 0, N) if(isPrime[i]) primes.push_back(i);

    ll cnt = DnC(0);
    ll total = (ll)N*(N-1)/2;
    // cout << cnt << ' ' << total << '\n';
    cout << fixed << setprecision(10) << (ld)cnt/total << '\n';
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