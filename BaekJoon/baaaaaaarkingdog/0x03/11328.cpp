#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int TC;
    string first, second;
    int firstarr[26], secondarr[26];
    cin >> TC;
    for(int i = 0; i<TC; ++i){
        fill(firstarr, firstarr+26, 0);
        fill(secondarr, secondarr+26, 0);
        cin >> first >> second;
        for(auto e: first){
            firstarr[e-'a'] += 1;
        }
        for(auto e: second){
            secondarr[e-'a'] += 1;
        }
        bool strfry;
        strfry = true;
        for(int j = 0; j<26; ++j){
            if (firstarr[j] != secondarr[j]){
                strfry = false;
            }
        }
        if(strfry){
            cout << "Possible" << "\n";
        }
        else{
            cout << "Impossible" << "\n";
        }
    }
}