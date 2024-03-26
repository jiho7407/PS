#include <bits/stdc++.h>

using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(NUint)
#define endl "\n"
typedef long long int;
typedef pair<int, int> pii;
typedef pair<int, int> pint;
const int mod = 1e9 + 7;

int N, Pos[4001];
int A[4001][2];
long double Min = 1e18;
const int aaa = 4;
const int divide = 4000/aaa;

void Solve(int r1, int r2, int r3){
    for(int i=1; i<=N; i++) Pos[i] = i;

    // 전체 point를 10개로 분할했을 때, r1, r2, r3 구간에 해당하는 것만 선택할 수 있음
    vector<int> V;
    if(r1 == r2 && r2 == r3){
        for(int i = 0; i < divide; i++)
            for(int j = i+1; j < divide; j++){
                if(0 < r1 * divide + i && r1 * divide + j <= N)
                    V.push_back((r1 * divide + i) * 10000 + r1 * divide + j);
            }
    } else if(r1 == r2){
        for(int i = 0; i < divide; i++)
            for(int j = 0; j < divide; j++){
                if(0 < r1 * divide + i && r3 * divide + j <= N) V.push_back((r1 * divide + i) * 10000 + r3 * divide + j);
            }
    } else {
        for(int i = 0; i < divide; i++)
            for(int j = 0; j < divide; j++){
                if(0 < r1 * divide + i && r2 * divide + j <= N) V.push_back((r1 * divide + i) * 10000 + r2 * divide + j);
                if(0 < r1 * divide + i && r3 * divide + j <= N) V.push_back((r1 * divide + i) * 10000 + r3 * divide + j);
                if(0 < r2 * divide + i && r3 * divide + j <= N) V.push_back((r2 * divide + i) * 10000 + r3 * divide + j);
            }
    }

    if(V.size() < 3) return;
    // Convert vector to array
    int idx = V.size();
    int arr[idx];
    for (size_t i = 0; i < V.size(); ++i) {
        arr[i] = V[i];
    }

    sort(arr, arr + idx, [&](int a, int b){
        int i = a / 10000, j = a % 10000;
        int x = b / 10000, y = b % 10000;
        return tie(A[i][0], A[i][1], A[j][0], A[j][1]) < tie(A[x][0], A[x][1], A[y][0], A[y][1]);
    });

    for(int i = 0 , j = 0; i < idx; i = j){
        while(j < idx){
            int x = arr[i] / 10000, y = arr[i] % 10000;
            int u = arr[j] / 10000, v = arr[j] % 10000;
            if(A[x] == A[u] || A[x] == A[v] || A[y] == A[u] || A[y] == A[v]) j++;
            else break;
        }
        for(int k = i; k < j; k++){
            //int u = V[k].i, v = V[k].j; // Point id
            int u = arr[k] / 10000, v = arr[k] % 10000;
            if(Pos[u] > Pos[v]) swap(u, v);
            if(Pos[u] > 1){
                //Point p1 = A[Pos[u]], p2 = A[Pos[v]], p3 = A[Pos[u]-1];
                long double a = sqrt((A[Pos[u]][0] - A[Pos[v]][0]) * (A[Pos[u]][0] - A[Pos[v]][0]) + (A[Pos[u]][1] - A[Pos[v]][1]) * (A[Pos[u]][1] - A[Pos[v]][1]));
                long double b = sqrt((A[Pos[v]][0] - A[Pos[u]-1][0]) * (A[Pos[v]][0] - A[Pos[u]-1][0]) + (A[Pos[v]][1] - A[Pos[u]-1][1]) * (A[Pos[v]][1] - A[Pos[u]-1][1]));
                long double c = sqrt((A[Pos[u]-1][0] - A[Pos[v]][0]) * (A[Pos[u]-1][0] - A[Pos[v]][0]) + (A[Pos[u]-1][1] - A[Pos[v]][1]) * (A[Pos[u]-1][1] - A[Pos[v]][1]));
                long double s = (a + b + c) / 2;
                if(s == 0) Min = 0;
                else Min = min(Min, 2 * sqrt(s * (s - a) * (s - b) * (s - c)) / max({a, b, c}));
            }
            if(Pos[v] < N){
                //Point p1 = A[Pos[u]], p2 = A[Pos[v]], p3 = A[Pos[v]+1];
                long double a = sqrt((A[Pos[u]][0] - A[Pos[v]][0]) * (A[Pos[u]][0] - A[Pos[v]][0]) + (A[Pos[u]][1] - A[Pos[v]][1]) * (A[Pos[u]][1] - A[Pos[v]][1]));
                long double b = sqrt((A[Pos[v]][0] - A[Pos[v]+1][0]) * (A[Pos[v]][0] - A[Pos[v]+1][0]) + (A[Pos[v]][1] - A[Pos[v]+1][1]) * (A[Pos[v]][1] - A[Pos[v]+1][1]));
                long double c = sqrt((A[Pos[v]+1][0] - A[Pos[u]][0]) * (A[Pos[v]+1][0] - A[Pos[u]][0]) + (A[Pos[v]+1][1] - A[Pos[u]][1]) * (A[Pos[v]+1][1] - A[Pos[u]][1]));
                long double s = (a + b + c) / 2;
                if(s == 0) Min = 0;
                else Min = min(Min, 2 * sqrt(s * (s - a) * (s - b) * (s - c)) / max({a, b, c}));
            }

        }
    }
}

int main(){
    fastio;
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i][0] >> A[i][1];

    for(int i = 1; i <= N; i++)
        for(int j = i+1; j <= N; j++)
            if(A[i][0] > A[j][0]) swap(A[i][0], A[j][0]), swap(A[i][1], A[j][1]);

    for(int i = 0; i < aaa; i++) Solve(i,i,i);
    for(int i = 0; i < aaa; i++) for(int j = i+1; j < aaa; j++) Solve(i,i,j);
    for(int i = 0; i < aaa; i++) for(int j = i+1; j < aaa; j++) for(int k = j+1; k < aaa; k++) Solve(i,j,k);

    cout << fixed << setprecision(10) << Min << endl;
    return 0;
}