#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> pdd;
typedef long long ll;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
int x, y;
vector<pdd> points;

int CCW(pdd a, pdd b, pdd c){
    ll result = 1LL*(b.first-a.first)*(c.second-b.second)
                -1LL*(b.second-a.second)*(c.first-b.first);
    if(result>0) return 1;
    else if (result==0) return 0;
    else return -1;
}

bool cmp1(pdd a, pdd b){
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

bool cmp2(pdd &a, pdd &b){
    int temp = CCW(points[0], a, b);
    if(temp != 0) return temp>0;
    return a.second < b.second || a.second == b.second && a.first < b.first;
}

double dist(pdd a, pdd b, pdd c){
    // a와 b가 이루는 직선과 c 사이의 거리
    if(a.first == b.first) return abs(c.first - a.first);
    
    double m = (b.second - a.second) / (b.first - a.first);
    double n = a.second - m*a.first;
    return abs(m*c.first - c.second + n) / sqrt(m*m + 1);
}

int main(){
    fastio();
    int TC = 0;
    while(true){
        TC++;
        cin >> N;
        if(N==0) break;

        points.clear();
        for(int i = 0; i<N; i++){
            cin >> x >> y;
            points.push_back({x, y});
        }
        sort(points.begin(), points.end(), cmp1);
        sort(points.begin()+1, points.end(), cmp2);
        vector<pdd> cvh = {points[0], points[1]};
        for(int i = 2; i<N; i++){
            while(cvh.size() >= 2 && CCW(cvh[cvh.size()-2], cvh[cvh.size()-1], points[i]) != 1) cvh.pop_back();
            cvh.push_back(points[i]);
        }

        double ans = 10000000000;
        for(int i = 0; i<cvh.size(); i++){
            double temp = 0;
            for(int j = 0; j<cvh.size()-2; j++){
                temp = max(temp, dist(cvh[i], cvh[(i+1)%cvh.size()], cvh[(i+2+j)%cvh.size()]));
            }
            ans = min(ans, temp);
        }
        
        double roundans = ceil(ans*100)/100;
        cout << "Case " << TC << ": ";
        cout << fixed << setprecision(2) << roundans << "\n";
    }
    return 0;
}