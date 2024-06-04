// Convex Hull
// 볼록 껍질

int N;
vector<pll> points;
vector<pll> hull;

// AB x AC
ll ccw(pll a, pll b, pll c){
    pll ab = {b.first - a.first, b.second - a.second};
    pll ac = {c.first - a.first, c.second - a.second};
    ll ret = ab.first*ac.second - ab.second*ac.first;
    if(ret > 0) return 1;
    if(ret < 0) return -1;
    return 0;
}

// AB x CD
ll cccw(pll a, pll b, pll c, pll d){
    pll ab = {b.first - a.first, b.second - a.second};
    pll cd = {d.first - c.first, d.second - c.second};
    ll ret = ab.first*cd.second - ab.second*cd.first;
    if(ret > 0) return 1;
    if(ret < 0) return -1;
    return 0;
}

// AB^2
ll dist(pll a, pll b){
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

// sort by x, y
bool cmp(pll a, pll b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

// sort by angle
bool cmp2(pll a, pll b){
    return ccw(points[0], a, b)>0 || ccw(points[0], a, b)==0 && a < b;
}

// make convex hull
void makehull(){
    sort(points.begin(), points.end(), cmp);
    sort(points.begin()+1, points.end(), cmp2);
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    rep(i, 2, N){
        while(hull.size() >= 2){
            pll a = hull[hull.size()-2];
            pll b = hull[hull.size()-1];
            pll c = points[i];
            if(ccw(a, b, c) <= 0){
                hull.pop_back();
            }else{
                break;
            }
        }
        hull.push_back(points[i]);
    }
    return;
}

// rotating calipers
ll rotating_calipers(){
    ll mx = 0, sz = hull.size();
    ll bar2 = 1;
    rep(bar1, 0, sz){
        while(1){
            if(cccw(hull[bar1], hull[(bar1+1)%sz], hull[bar2], hull[(bar2+1)%sz]) <= 0) break;
            mx = max(mx, dist(hull[bar1], hull[bar2]));
            bar2 = (bar2+1)%sz;            
        }
        ll nd = dist(hull[bar1], hull[bar2]);
        mx = max(mx, nd);
    }
    return mx;
}