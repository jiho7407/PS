#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, P;
string S, ans;

string calc(string s){
    stack<string> st;
    stack<string> result;
    bool inmul = false;
    int n = s.size();

    rep(i, 0, n){
        char ch = s[i];

        if(ch == '+' || ch == '*') result.push(string(1, ch));
        else if(ch == '('){
            int depth = 0;
            string tmp = "";
            while(i < n){
                if(s[i] == '(') depth++;
                else if(s[i] == ')') depth--;
                tmp += s[i];
                if(depth == 0) break;
                i++;
            }
            result.push("(" + calc(tmp.substr(1, tmp.size()-2)) + ")");
        }
        else{
            string num(1, ch);
            while(i+1 < n && isdigit(s[i+1])){
                num += s[i+1];
                i++;
            }
            result.push(num);
        }

        if(!result.empty() && result.top().back() == '*');
    }

    stack<string> tmp;
    while(!result.empty()){
        tmp.push(result.top());
        result.pop();
    }

    vector<string> tmp1, tmp2;
    while(!tmp.empty()) tmp1.push_back(tmp.top()), tmp.pop();

    inmul = false;
    rep(i, 0, tmp1.size()){
        if(tmp1[i] == "*"){
            string a = tmp2.back(); tmp2.pop_back();
            string b = tmp1[i+1]; i++;
            tmp2.push_back(a + "*" + b);
            if(!inmul) tmp2.back() = "(" + tmp2.back();
            inmul = true;
        }
        else{
            if(inmul) tmp2.back() += ")";
            inmul = false;
            tmp2.push_back(tmp1[i]);
        }
    }
    if(inmul) tmp2.back() += ")";

    string rettt = "";
    for(auto x : tmp2) rettt += x;

    // stack<int> idxs;
    // rep(i, 0, rettt.size() - 1){
    //     if(rettt[i] == '(') idxs.push(i);
    //     else if(rettt[i] == ')') idxs.pop();
    // }
    // if(!idxs.empty() && idxs.top() == 0) rettt = rettt.substr(1, rettt.size()-2);

    // cout << s << " => " << rettt << endl;
    return rettt;
}

void solve(){
    cin >> N >> P;
    cin >> S;

    ans = calc(S);
    if(ans.size() > 100) assert(false);
    cout << ans.size() << '\n' << ans << '\n';
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}