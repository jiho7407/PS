#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct Queue{
    int arr[10100];
    int front = 0, back = 0;

    bool empty(){
        if(front == back) return true;
        else return false;
    }

    int size(){
        return back - front;
    }

    int push(int x){
        arr[back] = x;
        back += 1;
    }

    int pop(){
        if(empty()) return -1;
        else{
            int tmp = arr[front];
            front += 1;
            return tmp;
        }
    }

    int front(){
        if(empty()) return -1; 
        else return arr[front];
    }

    int back(){
        if(empty()) return -1;
        else return arr[back-1];
    }
}

#include <queue>

void solve(){
    queue<int> Q;
    Q.push(1);
    Q.push(2);
    cout << Q.front() << '\n'; // 1
    cout << Q.back() << '\n'; // 2
    cout << Q.pop() << '\n'; // 1
    cout << Q.empty() << '\n'; // false
    cout << Q.size() << '\n'; // 1
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}