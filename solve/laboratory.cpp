#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	string S, T;
	cin >> S >> T;
	cout << (int)(S.compare(0, T.size(), T)) << '\n';
	return 0;
}