#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> lst;
vector<int> nxt, front, back;

int findfront(int a) {
    if (a == front[a]) return a;
    front[a] = findfront(front[a]);
    return front[a];
}

int findback(int a) {
    if (a == back[a]) return a;
    back[a] = findback(back[a]);
    return back[a];
}

void merge(int a, int b) {
    int af = findfront(a);
    int ab = findback(a);
    int bf = findfront(b);
    int bb = findback(b);
    front[bf] = af;
    back[ab] = bb;
    nxt[ab] = bf;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    lst.resize(N);
    nxt.resize(N + 1);
    front.resize(N + 1);
    back.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> lst[i - 1];
        nxt[i] = i;
        front[i] = i;
        back[i] = i;
    }

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    int idx = findfront(1);
    while (idx != nxt[idx]) {
        cout << lst[idx - 1];
        idx = nxt[idx];
    }
    cout << lst[idx - 1];

    return 0;
}
