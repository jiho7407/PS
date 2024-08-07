// 접미사 배열
// S[i:]의 사전순 정렬
// NlogN

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

// 매내쳐
// S[i]를 중심으로 하는 가장 긴 팰린드롬의 반지름
const int mxN = 5e6;
struct Manacher{
    int N, r = 0, p = 0;
    int A[mxN];
    Manacher(string T){
        string S = "#";
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


// Z 배열
// S와 S[i:]의 최장 공통 접두사 길이
struct Zarray{
    string S;
    int N;
    int Z[1000000];

    Zarray(string S): S(S){
        N = S.size();
        Z[0] = N;
        int l = 0, r = 0;
        rep(i, 1, N){
            if(i <= r) Z[i] = min(Z[i-l], r-i);
            while(i+Z[i] < N && S[Z[i]] == S[i+Z[i]]) Z[i]++;
            if(i>r) l = i;
            r = max(r, i+Z[i]-1);
        }
    }
};