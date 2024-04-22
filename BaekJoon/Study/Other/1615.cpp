#include <bits/stdc++.h>
using namespace std;

int tree[4001];
pair<int, int> lst[2000000];

void init(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main(){
    init(); //main함수에 init()추가

    int N, M;
    cin >> N >> M;
    fill(tree, tree+(2*N), 0);
    
    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        lst[i] = {a, b};
    }

    sort(lst, lst+M);

    long long ans;
    ans = 0;
    int cmd, s, e, temp, idx;
    for(int i=0; i<M; i++){
        cmd = lst[i].second;
        s = cmd + N;
        e = 2*N;
        temp = 0;
        while(s < e){
            if(s%2){
                temp += tree[s];
                s += 1;
            }
            if(e%2){
                e -= 1;
                temp += tree[e];
            }
            s /= 2;
            e /= 2;
        }
        ans += temp;

        idx = N + cmd - 1;
        while(idx){
            tree[idx] += 1;
            idx /= 2;
        }
    }

    cout << ans;
}