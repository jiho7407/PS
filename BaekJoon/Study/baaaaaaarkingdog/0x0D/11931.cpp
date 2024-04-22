#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

bool desc(int a, int b){
    return a>b;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end(), desc);
    for(int i = 0; i<n; i++){
        cout << arr[i] << "\n";
    }
}