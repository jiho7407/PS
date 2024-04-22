#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
int root[100010];

long long weight[100010];

int findroot(int a){
    if(a == root[a]) return a;

    int pa = findroot(root[a]);
    weight[a] += weight[root[a]];
    root[a] = pa;
    return pa;
}

void merge(int a, int b, int w){
    int aroot, broot;
    aroot = findroot(a);
    broot = findroot(b);
    if(aroot==broot) return;

    weight[broot] = weight[a] - weight[b] + w;
    root[broot] = aroot;
    return;
}

int main(){
    fastio();
    while(true){
        cin >> N >> M;
        if(N==0&&M==0) break;
        fill(weight, weight+N+1, 0);
        for(int i = 0; i<=N; i++){
            root[i] = i;
        }
        for(int i = 0; i<M; i++){
            char cmd;
            int a, b, w;
            cin >> cmd;
            if(cmd=='!'){
                cin >> a >> b >> w;
                merge(a, b, w);
            }
            else{
                cin >> a >> b;
                if(findroot(a) != findroot(b)) cout << "UNKNOWN\n";
                else{
                    cout << weight[b] - weight[a] << "\n";
                }
            }
        }
    }

    return 0;
}