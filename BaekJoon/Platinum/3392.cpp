#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxSz = 30010;
int N;
vector<tuple<int, bool, int, int>> query; // x좌표, 시작변 유무, y1, y2
int segcnt[mxSz*4], poscnt[mxSz*4]; // 선분 개수 관리 세그트리, 1 이상 변 개수 관리 세그트리


bool cmp(tuple<int, bool, int, int> a, tuple<int, bool, int, int> b){
    if(get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b); // x좌표가 같을경우 시작변이 먼저 오도록
    return get<0>(a) < get<0>(b);
}

void update(int node, int start, int end, int left, int right, int diff){
    if(start > right || end < left) return;
    if(left <= start && end <= right) segcnt[node] += diff;
    else{
        int mid = (start + end) / 2;
        update(node*2, start, mid, left, right, diff);
        update(node*2+1, mid+1, end, left, right, diff);
    }
    if(segcnt[node]) poscnt[node] = end - start + 1;
    else{
        if(start == end) poscnt[node] = 0;
        else poscnt[node] = poscnt[node*2] + poscnt[node*2+1];
    }
}

void solve(){
    cin >> N;
    for(int i = 0; i<N; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        query.push_back({x1, true, y1, y2-1}); // y좌표 3은 3~4 선분을 뜻함
        query.push_back({x2, false, y1, y2-1});
    }
    sort(query.begin(), query.end(), cmp);
    ll ans = 0;

    ll lastx = -1;
    for(int i = 0; i<query.size(); i++){
        auto [x, start, y1, y2] = query[i];
        if(i>0){ // 처음은 빼고
            ll width = x - lastx;
            ll height = poscnt[1]; // 선분이 1개 이상인 부분의 개수 합
            ans += width * height;
        }
        lastx = x;

        if(start) update(1, 0, mxSz, y1, y2, 1);
        else update(1, 0, mxSz, y1, y2, -1);
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