#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mx = 1'000'010;
// const int mx = 6;
int N, x, y, v, idx;
vector<pii> X[mx], Y[mx];
int Xsum[mx], Ysum[mx];
pii Xseg[2*mx], Yseg[2*mx];
int tempX[mx], tempY[mx];

bool cmp(int a, int b){
    return a>b;
}

pii getTwo(pii A, pii B){
    int temp[4] = {A.first, A.second, B.first, B.second};
    sort(temp, temp+4, cmp);
    return pii(temp[0], temp[1]);
}

int main(){
    fastio();

    // 초기화
    fill(Xsum, Xsum+mx, 0);
    fill(Ysum, Ysum+mx, 0);
    fill(Xseg, Xseg+2*mx, pii(0, 0));
    fill(Yseg, Yseg+2*mx, pii(0, 0));

    cin >> N;
    // 입력받기
    while(N--){
        cin >> x >> y >> v;
        X[x].push_back({y, v});
        Xsum[x] += v;
        Y[y].push_back({x, v});
        Ysum[y] += v;
    }
    
    // 가로 세방, 세로 세방
    int ans = 0;

    copy(Xsum, Xsum+mx, tempX);
    sort(tempX, tempX+mx, cmp);
    ans = max(ans, tempX[0] + tempX[1] + tempX[2]);

    copy(Ysum, Ysum+mx, tempY);
    sort(tempY, tempY+mx, cmp);
    ans = max(ans, tempY[0] + tempY[1] + tempY[2]);

    
    // 세그트리 만들기
    for(int i = 0; i<mx; i++){
        Xseg[mx+i].first = Xsum[i];
        Yseg[mx+i].first = Ysum[i];
    }
    for(int i = mx-1; i>0; i--){
        Xseg[i] = getTwo(Xseg[i*2], Xseg[i*2+1]);
        Yseg[i] = getTwo(Yseg[i*2], Yseg[i*2+1]);
    }

    // X Y Y
    for(int i = 0; i<mx; i++){
        if(X[i].empty()) continue;
        for(auto yv: X[i]){
            idx = mx+yv.first;
            Yseg[idx].first -= yv.second;
            idx /= 2;
            while(idx>0){
                Yseg[idx] = getTwo(Yseg[idx*2], Yseg[idx*2+1]);
                idx /= 2;
            }
        }
        ans = max(ans, Xsum[i] + Yseg[1].first + Yseg[1].second);
        for(auto yv: X[i]){
            idx = mx+yv.first;
            Yseg[idx].first += yv.second;
            idx /= 2;
            while(idx>0){
                Yseg[idx] = getTwo(Yseg[idx*2], Yseg[idx*2+1]);
                idx /= 2;
            }
        }
    }

    // Y X X
    for(int i = 0; i<mx; i++){
        if(Y[i].empty()) continue;
        for(auto xv: Y[i]){
            idx = mx+xv.first;
            Xseg[idx].first -= xv.second;
            idx /= 2;
            while(idx>0){
                Xseg[idx] = getTwo(Xseg[idx*2], Xseg[idx*2+1]);
                idx /= 2;
            }
        }
        ans = max(ans, Ysum[i] + Xseg[1].first + Xseg[1].second);
        for(auto xv: Y[i]){
            idx = mx+xv.first;
            Xseg[idx].first += xv.second;
            idx /= 2;
            while(idx>0){
                Xseg[idx] = getTwo(Xseg[idx*2], Xseg[idx*2+1]);
                idx /= 2;
            }
        }
    }

    cout << ans;
    return 0;
}