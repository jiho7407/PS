#include <bits/stdc++.h>
using namespace std;

long long N, M, Q;
vector<pair<long long, long long>> A, B, C, D, E;
vector<vector<long long>> calc;
long long root[50100];
long long cnt;

long long findroot(long long a) {
    if (a == root[a]) return a;
    root[a] = findroot(root[a]);
    return root[a];
}

bool merge(long long a, long long b) {
    long long af = findroot(a);
    long long bf = findroot(b);
    if(af==bf){
        return false;
    }
    else if(af<bf){
        root[bf] = af;
    }
    else{
        root[af] = bf;
    }
    return true;
}

long long solve(long long a, long long b, long long c, long long d, long long e){
    long long ans = 10000000000000;
    for(auto L: calc){
        ans = min(ans, a*L[0]+b*L[1]+c*L[2]+d*L[3]+e*L[4]);
    }
    return ans;
}

long long connect(vector<pair<long long, long long>> vec){
    long long tempcnt = 0;
    for(auto p: vec){
        if(cnt==N-1) return tempcnt;
        if(merge(p.first, p.second)){
            cnt++;
            tempcnt++;
        }
    }
    return tempcnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> Q;
    long long u, v;
    char z;
    for(long long i = 0; i<M; i++){
        cin >> u >> v >> z;
        switch(z) {
            case 'A':
                A.push_back({u, v});
                break;
            case 'B':
                B.push_back({u, v});
                break;
            case 'C':
                C.push_back({u, v});
                break;
            case 'D':
                D.push_back({u, v});
                break;
            case 'E':
                E.push_back({u, v});
                break;
        }
    }

    vector<char> elements = {'A', 'B', 'C', 'D', 'E'};
    do {
        for(long long i = 0; i<=N; i++){
            root[i] = i;
        }
        long long a, b, c, d, e;
        a = b = c = d = e = cnt = 0;
        for (char element : elements) {
            switch(element) {
                case 'A':
                    a += connect(A);
                    break;
                case 'B':
                    b += connect(B);
                    break;
                case 'C':
                    c += connect(C);
                    break;
                case 'D':
                    d += connect(D);
                    break;
                case 'E':
                    e += connect(E);
                    break;
            }
        }
        calc.push_back({a, b, c, d, e});
    } while (std::next_permutation(elements.begin(), elements.end()));
    for(long long i = 0; i<Q; i++){
        long long a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        cout << solve(a, b, c, d, e) << "\n";
    }

    return 0;
}
