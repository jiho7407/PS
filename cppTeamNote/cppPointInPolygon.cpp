// from 1688.cpp (/BaekJoon/Other/1688.cpp)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
vector<pll> poly;

pll ptv(pll a, pll b){
    return {b.first - a.first, b.second - a.second};
}

int ccw(pll a, pll b){
    ll ret = a.first*b.second - a.second*b.first;
    if(ret > 0) return 1;
    else if(ret == 0) return 0;
    else return -1;
}

bool inpoly(pll p, vector<pll> &poly){
    int cnt = 0;
    for(int i = 0; i<poly.size(); i++){
        pll a = poly[i], b = poly[(i+1)%poly.size()];
        if(a.second > b.second) swap(a, b);
        if(ccw(ptv(a, b), ptv(a, p)) == 0){
            if(min(a.first, b.first) <= p.first && p.first <= max(a.first, b.first) && a.second <= p.second && p.second <= b.second) return true;
        }
        if(a.second <= p.second && p.second < b.second){ 
            if((b.second - a.second)*(p.first - a.first) < (p.second - a.second)*(b.first - a.first)) cnt++;
        }
    }
    return cnt%2 == 1;
}