#include <bits/stdc++.h>
using namespace std;

vector<string> arr;
int a[20];

int main(){
    int L, C;
    cin >> L >> C;
    string temp;
    for(int i = 0; i<C; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());

    for(int i = 0; i<C; i++){
        if(i<L) a[i] = 0;
        else a[i] = 1;
    }
    string vowels = "aeiou";
    do{
        int vowel = 0, cons = 0;
        for(int i = 0; i<C; i++){
            if(a[i]==0){
                temp = arr[i];
                if(vowels.find(temp) != string::npos) vowel++;
                else cons++;
            }
        }
        if(vowel == 0 || cons <= 1) continue;
        for(int i = 0; i<C; i++){
            if(a[i]==0) cout << arr[i];
        }
        cout << "\n";
    }while(next_permutation(a, a+C));
}