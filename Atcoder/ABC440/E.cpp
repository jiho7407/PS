#include <iostream>
#include <vector>
using namespace std;

class LazySegmentTree {
private:
    int size;
    vector<long long> tree;
    vector<long long> lazy;

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

public:
    LazySegmentTree(int size) : size(size), tree(4 * size), lazy(4 * size, 0) {}

    void update_range(int node, int start, int end, int left, int right, long long val) {
        propagate(node, start, end);
        if (start > right || end < left) return;
        if (left <= start && end <= right) {
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[node * 2] += val;
                lazy[node * 2 + 1] += val;
            }
            return;
        }
        int mid = (start + end) / 2;
        update_range(node * 2, start, mid, left, right, val);
        update_range(node * 2 + 1, mid + 1, end, left, right, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    long long query(int node, int start, int end, int idx) {
        propagate(node, start, end);
        if (start == end) return tree[node];
        int mid = (start + end) / 2;
        if (idx <= mid) return query(node * 2, start, mid, idx);
        else return query(node * 2 + 1, mid + 1, end, idx);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    LazySegmentTree tree(N);
    for (int i = 0; i < N; ++i) {
        int cmd;
        cin >> cmd;
        tree.update_range(1, 0, N - 1, i, i, cmd);
    }

    while (M--) {
        int cmd;
        cin >> cmd;
        long long val = tree.query(1, 0, N - 1, cmd);

        tree.update_range(1, 0, N - 1, cmd, cmd, -val);
        tree.update_range(1, 0, N - 1, 0, N - 1, val / N);

        int R = val % N;

        if (cmd + R < N) {
            tree.update_range(1, 0, N - 1, cmd + 1, cmd + R, 1);
        } else {
            tree.update_range(1, 0, N - 1, cmd + 1, N - 1, 1);
            tree.update_range(1, 0, N - 1, 0, cmd + R - N, 1);
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << tree.query(1, 0, N - 1, i) << " ";
    }
    cout << "\n";

    return 0;
}
