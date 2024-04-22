#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> pdd;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxN = 105;
vector<pdd> points;
pdd S, E;
int N;
double X, Y;
double times[mxN][mxN];

double dist(pdd &A, pdd &B){
    return sqrt(pow(A.first-B.first, 2) + pow(A.second-B.second, 2));
}

int main(){
    fastio();
    cin >> X >> Y;
    S = pdd(X, Y);
    cin >> X >> Y;
    E = pdd(X, Y);
    cin >> N;

    points.push_back(S);
    for(int i = 0; i<N; i++){
        cin >> X >> Y;
        points.push_back(pdd(X, Y));
    }
    points.push_back(E);
    for(int i = 0; i<N+2; i++){
        for(int j = 0; j<N+2; j++){
            double tempdist = dist(points[i], points[j]);
            if(i == 0 || i == N+1) times[i][j] = tempdist/5;
            else times[i][j] = min(tempdist/5, abs(tempdist-50)/5 + 2);
        }
    }
    for(int k = 0; k<N+2; k++){
        for(int i = 0; i<N+2; i++){
            for(int j = 0; j<N+2; j++){
                times[i][j] = min(times[i][j], times[i][k] + times[k][j]);
            }
        }
    }
    cout << times[0][N+1];
    return 0;
}