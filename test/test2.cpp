#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M;
int arr[100005];

struct Node {
    Node *left, *right, *p;
    ll sz;
    ll lsum, rsum, mx;
    ll val;
    bool inv;
    Node() : left(nullptr), right(nullptr), p(nullptr) {};
} *root, *ptr[100005];

void push(Node *cur) {
    if(!cur->inv) return ;
    swap(cur->left, cur->right);
    swap(cur->lsum, cur->rsum);
    if(cur->left) cur->left->inv = !cur->left->inv;
    if(cur->right) cur->right->inv = !cur->right->inv;
    cur->inv = false;
}

void update(Node *cur) {
    push(cur);
    cur->sz = 1;
    if(cur->val) cur->mx = cur->lsum = cur->rsum = 1;
    else cur->mx = cur->lsum = cur->rsum = 0;
    if(cur->left && cur->right) {
        push(cur->left); push(cur->right);
        cur->sz += cur->left->sz + cur->right->sz;
        cur->lsum = cur->left->lsum;
        if(cur->left->sz == cur->left->lsum && cur->val) cur->lsum += cur->right->lsum + cur->val;
        cur->rsum = cur->right->rsum;
        if(cur->right->sz == cur->right->rsum && cur->val) cur->rsum += cur->left->rsum + cur->val;
        cur->mx = max(cur->right->mx, cur->left->mx);
        if(cur->val) cur->mx = max(cur->mx, cur->left->rsum + cur->right->lsum + 1);
        cur->mx = max(cur->mx, max(cur->lsum, cur->rsum));
        cur->mx = max(cur->mx, max(cur->left->rsum+cur->val, cur->right->lsum+cur->val));
    }
    else if(cur->left) {
        push(cur->left);
        cur->sz += cur->left->sz;
        cur->lsum = cur->left->lsum;
        if(cur->left->lsum == cur->left->sz) cur->lsum = cur->left->sz + cur->val;
        cur->rsum = cur->val? cur->val + cur->left->rsum : 0;
        cur->mx = max(cur->left->mx, cur->val);
        cur->mx = max(cur->mx, cur->left->rsum + cur->val);
        cur->mx = max(cur->mx, max(cur->lsum, cur->rsum));
    }
    else if(cur->right) {
        push(cur->right);
        cur->sz += cur->right->sz;
        cur->rsum = cur->right->rsum;
        if(cur->right->rsum == cur->right->sz) cur->rsum = cur->right->sz + cur->val;
        cur->lsum = cur->val? cur->val + cur->right->lsum : 0;
        cur->mx = max(cur->val, cur->right->mx);
        cur->mx = max(cur->mx, cur->val + cur->right->lsum);
        cur->mx = max(cur->mx, max(cur->lsum, cur->rsum));
    }
}

void rotate(Node *cur) {
    Node *p, *b;
    p = cur->p;
    if(!p) return ;
    push(p);
    push(cur);
    Node *pp = p->p;
    if(p->left == cur) {
        p->left = b = cur->right;
        cur->right = p;
    }
    else {
        p->right = b = cur->left;
        cur->left = p;
    }
    p->p = cur;
    cur->p = pp;
    if(b) b->p = p;
    if(!pp) root = cur;
    else {
        if(pp->left == p) pp->left = cur;
        else pp->right = cur;
    }
    update(p); update(cur);
}

void splay(Node *cur) {
    while(cur->p) {
        Node *p = cur->p;
        Node *pp = p->p;
        if(pp) {
            if((pp->left == p) == (p->left == cur)) rotate(p);
            else rotate(cur);
        }
        rotate(cur);
    }
}

void findKth(ll k) {
    Node *p = root;
    push(p);
    while(1) {
        while(p->left && p->left->sz > k) {
            p = p->left;
            push(p);
        }
        if(p->left) k -= p->left->sz;
        if(!k) break;
        else --k;
        p = p->right;
        push(p);
    }
    splay(p);
}

Node* segment(int l, int r) {
    if(l != 1 && r != N) {
        findKth(l-2);
        Node *p = root;
        root = p->right;
        root->p = nullptr;
        findKth(r-l+1);
        root->p = p;
        p->right = root;
        root = p;
        return root->right->left;
    }
    else if(l == 1 && r == N) {
        splay(ptr[(N+1)/2]);
        return root;
    }
    else if(l == 1) {
        findKth(r);
        return root->left;
    }
    else if(r == N) {
        if(l != r) findKth(l-2);
        else findKth(N-2);
        return root->right;
    }
}

void init() {
    Node *p;
    root = p = new Node;
    p->val = arr[1];
    p->inv = false;
    ptr[1] = p;
    for(int i=2;i<=N;++i) {
        p->right = new Node;
        p->right->p = p;
        p = p->right;
        p->val = arr[i];
        p->inv = false;
        ptr[i] = p;
    }
    while(p) {
        update(p); p = p->p;
    }
}

void flip(int l, int r) {
    Node *p = segment(l,r);
    p->inv = !p->inv;
    while(p) {
        update(p); p = p->p;
    }
}

void print(Node *cur) {
    if(cur->left) print(cur->left);
    cout << cur->val << ' ';
    if(cur->right) print(cur->right);
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    ifstream cin("D:\\Programming-D\\PS\\test\\input.txt");
    cin >> N;
    for(int i=1;i<=N;++i) cin >> arr[i];
    init();
    cin >> M;
    for(int i=0;i<M;++i) {
        int q, l, r;
        cin >> q >> l >> r;
        if(q == 1) {
            flip(l,r);
        }
        else {
            Node * p = segment(l,r);
            cout << p->mx << '\n';
        }
    }
    return 0;
}