#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll dot(pll A, pll B){
    ll result = A.first*B.first + A.second*B.second;
    return result == 0;
}

ll cross(pll A, pll B){
    ll result = A.second*B.first - A.first*B.second;
    return result == 0;
}

ll leng(pll A){
    return A.first*A.first + A.second*A.second;
}



void solve(){
    pair<ll, ll> points[4];
    for(int i = 0; i<4; i++){
        ll a, b;
        cin >> a >> b;
        points[i] = {a, b};
    }
    bool Sq = true, Rh = true;

    vector<pll> v(4);
    for (int i=0;i<4;i++){
        int j = (i+1)%4;
        v[i] = {points[j].first - points[i].first, points[j].second - points[i].second};
    }
    for (int i=0;i<4;i++){
        int j = (i+1)%4;
        if (!dot(v[j],v[i])){Sq=  false;}
        if (leng(v[j])!=leng(v[i])){Rh = false;}
    }
    if(Sq&&Rh){cout << "square"; return;}
    if(Sq){cout << "rectangle"; return;}
    if(Rh){cout << "rhombus"; return;}

    int par = 0;
    if(cross(v[0], v[2])) par++;
    if(cross(v[1], v[3])) par++;

    if(par==2){cout << "parallelogram"; return;}
    if(par==1){cout << "trapezium"; return;}
    
    bool kite = false;
    if(leng(v[0]) == leng(v[1]) && leng(v[2]) == leng(v[3])) kite = true;
    if(leng(v[1]) == leng(v[2]) && leng(v[3]) == leng(v[0])) kite = true;
    if(kite) cout << "kite";
    else cout << "none";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}