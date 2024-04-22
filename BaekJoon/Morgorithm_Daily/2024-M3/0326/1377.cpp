#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, A[500010], sortA[500010];

int bin_search(int a){
    int l = 0, r = N-1, mid = 0;
    while(l<=r){
        mid = (l+r)/2;
        if(sortA[mid] <= a) l = mid+1;
        else if(sortA[mid]>a) r = mid-1;
    }
    return r;
}

int main(){
    fastio();
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> A[i];
    }
    copy(A, A+N, sortA);
    sort(sortA, sortA+N);
    int ans = 0;
    for(int i = 0; i<N; i++){
        ans = max(ans, i - bin_search(A[i]));
    }
    cout << ans+1;
    return 0;
}