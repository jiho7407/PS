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

int N;
string S;

// 접미사 배열
// S[i:]의 사전순 정렬
// NlogN

const int mxN = 1e5;
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

// 문자열 이분탐색

pii get_bound(int SA[],string T){
    int lb, up;

    // Lower Bound
    int lo = 0, hi = N;
    while(lo<hi){
        int mid = (lo+hi)>>1;
        if(S.compare(SA[mid], T.size(), T) < 0) lo = mid+1;
        else hi = mid;
    }
    lb = lo;

    // Upper Bound
    lo = 0, hi = N;
    while(lo<hi){
        int mid = (lo+hi)>>1;
        if(S.compare(SA[mid], T.size(), T) <= 0) lo = mid+1;
        else hi = mid;
    }
    up = hi;

    return {lb, up};
}

void solve(){
    cin >> S; N = S.size();
    SuffixArray SA(S);

    int Q; cin >> Q;
    while(Q--){
        string tmp; cin >> tmp;
        string T = "";
        T += tmp[0];
        int cnt = stoi(tmp.substr(1, tmp.size()-2));
        rep(i, 0, cnt) T += char(255);
        T += tmp[tmp.size()-1];
        auto [lb, up] = get_bound(SA.SA, T);
        cout << T << ' ' << lb << ' ' << up << '\n';
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