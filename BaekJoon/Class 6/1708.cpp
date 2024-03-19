#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
int x, y;
vector<pii> points;

int CCW(pii a, pii b, pii c){
    ll result = 1LL*(b.first-a.first)*(c.second-b.second)
                -1LL*(b.second-a.second)*(c.first-b.first);
    if(result>0) return 1;
    else if (result==0) return 0;
    else return -1;
}

bool cmp1(pii a, pii b){
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

bool cmp2(pii &a, pii &b){
    int temp = CCW(points[0], a, b);
    if(temp != 0) return temp>0;
    return a.second < b.second || a.second == b.second && a.first < b.first;
}

int main(){
    fastio();
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> x >> y;
        points.push_back({x, y});
    }
    sort(points.begin(), points.end(), cmp1);
    sort(points.begin()+1, points.end(), cmp2);
    vector<pii> cvh = {points[0], points[1]};
    for(int i = 2; i<N; i++){
        while(cvh.size() >= 2 && CCW(cvh[cvh.size()-2], cvh[cvh.size()-1], points[i]) != 1) cvh.pop_back();
        cvh.push_back(points[i]);
    }
    cout << cvh.size();
    return 0;
}