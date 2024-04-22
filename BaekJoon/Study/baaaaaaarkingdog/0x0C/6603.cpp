#include <bits/stdc++.h>
using namespace std;

int arr[20];
int a[20];

int main(){
    while(true){
        int cmd;
        cin >> cmd;
        if(cmd==0) break;
        for(int i = 0; i<cmd; i++){
            cin >> arr[i];
        }
        for(int i = 0; i<cmd; i++){
            if(i<6) a[i] = 0;
            else a[i] = 1;
        }
        do{
            for(int i = 0; i<cmd; i++){
                if(a[i]==0) cout << arr[i] << " ";
            }
            cout << "\n";
        }while(next_permutation(a, a+cmd));
        cout<<"\n";
    }
}