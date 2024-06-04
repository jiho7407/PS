#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxN = 1200000;
struct SuffixArray{
    string S;
    int N, cnt[mxN], ord[mxN], tmp[mxN], SA[mxN], LCP[mxN];

    SuffixArray(string S): S(S){
        N = S.size();
        makeSA();
        makeLCP();
    }

    void makeSA(){
        rep(i, 0, N){
            SA[i] = i;
            ord[i] = S[i];
        }
        int d = 1;
        int pnt = 1;
        while(1){
            // 기수 정렬
            // cnt: 같은 그룹의 개수, ord: 그룹 번호, SA: 정렬된 순서
            fill(cnt, cnt+mxN, 0);
            rep(i, 0, N) cnt[ord[min(i+d, N)]]++; // i+d번째 문자를 기준으로 그룹 나누기
            rep(i, 0, max(N, 255)) cnt[i+1] += cnt[i];
            for(int i = N-1; i>=0; i--) tmp[--cnt[ord[min(i+d, N)]]] = i;
            
            fill(cnt, cnt+mxN, 0);
            rep(i, 0, N) cnt[ord[i]]++; // i번째 문자를 기준으로 그룹 나누기
            rep(i, 0, max(N, 255)) cnt[i+1] += cnt[i];
            for(int i = N-1; i>=0; i--) SA[--cnt[ord[tmp[i]]]] = tmp[i];


            // 새로운 그룹 번호 부여
            if(pnt == N) break;
            pnt = 1;
            tmp[SA[0]] = 1;
            rep(i, 1, N){
                if(ord[SA[i-1]] != ord[SA[i]] || ord[SA[i-1]+d] != ord[SA[i]+d]) pnt++;
                tmp[SA[i]] = pnt;
            }
            rep(i, 0, N) ord[i] = tmp[i];
            d <<= 1;
        }
    }

    void makeLCP(){
        rep(i, 0, N) tmp[SA[i]] = i;
        for(int i=0, k=0; i<N; i++, k=max(k-1, 0)){
            if(tmp[i] == N-1) continue;
            for(int j=SA[tmp[i]+1]; S[i+k]==S[j+k]; k++);
            LCP[tmp[i]] = k;
        }
    }
};

struct Manacher{
    string S;
    int N, r = 0, p = 0;
    int A[mxN];
    Manacher(string T){
        S = "#";
        for(auto c : T){ S += c; S += '#'; }

        N = S.size();
        rep(i, 0, N){
            if(i <= r) A[i] = min(A[2*p-i], r-i);
            else A[i] = 0;

            while(1){
                if(i-A[i]-1 < 0 || i+A[i]+1 >= N) break; // 범위 밖으로 나간 경우
                if(S[i-A[i]-1] != S[i+A[i]+1]) break; // 대칭이 아닌 경우
                A[i]++;
            }

            if(r < i+A[i]){
                r = i+A[i];
                p = i;
            }
        }
    }
};

int endpal[mxN];

void solve(){
    int N, K; cin >> N >> K;
    string S; cin >> S;
    auto SA = new SuffixArray(S);
    auto MN = new Manacher(S);
    fill(endpal, endpal+N, -1);
    rep(i, 0, MN->N){
        if(MN->A[i] >= K){
            
            int left = (i-1)/2 - K/2;
            if(MN->A[i]%2==0) left++;
            int right = (i-1)/2 + K/2;
            if(K%2 && MN->A[i]%2 == 0){
                left--;
                right++;
            }
            // cout << i << " " << left << ' ' << right << '\n';
            if(endpal[left] == -1) endpal[left] = right;
            else endpal[left] = min(endpal[left], right);
        }
    }
    // rep(i, 0, MN->N) cout << MN->A[i] << ' ';
    // cout << '\n';
    for(int i = N-2; i>=0; i--){
        if(endpal[i] == -1) endpal[i] = endpal[i+1];
    }
    // rep(i, 0, N) cout << endpal[i] << ' ';
    // cout << '\n';
    ll ans = 0;
    rep(i, 0, N){
        if(endpal[SA->SA[i]] == -1) continue;
        int LCPleft = SA->SA[i] + SA->LCP[i];
        ans += max(0, N - max(LCPleft, endpal[SA->SA[i]]));
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