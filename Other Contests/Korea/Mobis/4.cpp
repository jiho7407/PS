#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ll long long
#define rep(i, l, r) for(int i = l; i<r; i++)
using namespace std;

ll ans[10000000];

void add(ll a, ll b, ll c, ll d){ // a 뒤에서, b c 지나고 d 앞에서 끝남
    // 가능 길이: (c-b+1) ~ (d-b);
    // 시작 길이: 0 ~ (b-a-1)
    ans[c-b+1] += 1;
    ans[c-a+1] -= 1;
    ans[d-b+1] -= 1;
    ans[d-a+1] += 1;
}

void imos(){
    rep(i, 1, 10000000){
        ans[i] += ans[i-1];
    }
}

vector<ll> solution(ll n, vector<ll> flags){
    if(flags.size() == 2) add(0, flags[0], flags[1], n+1);
    else if(flags.size() == 3){
        add(0, flags[0], flags[1], flags[2]);
        add(flags[0], flags[1], flags[2], n+1);
    }
    else{
        add(0, flags[0], flags[1], flags[2]);
        rep(i, 0, flags.size()-3){
            add(flags[i], flags[i+1], flags[i+2], flags[i+3]);
        }
        add(flags[flags.size()-3], flags[flags.size()-2], flags[flags.size()-1], n+1);
    }
    imos();
    imos();
    rep(i, 0, n+1){
        cout << i << ' ' << ans[i] << '\n';
    }
}

int main(){
    // ll n = 10; vector<ll> flags = {2, 4, 8};
    ll n = 20; vector<ll> flags = {1, 9, 14, 20};
    solution(n, flags);
}