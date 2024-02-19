#include <bits/stdc++.h>
using namespace std;

double algo(int x, int y, int k) {
    double res = 0;
    int a = max(x, (int)ceil((x + y) / 2 - 1));
    int b = min(y, (int)floor((x + y) / 2) + 1);
    
    if (a+2 < b) {
        for (int i = a; i <= b; i++) {
            if (i > k) {
                res += (1 + algo(x, i-1, k)) / (b - a + 1);
            }
            else if (i == k) {
                res += 1 / (b - a + 1);
            }
            else {
                res += (1+ algo(i+1, y, k)) / (b - a + 1);
            }
        }
    }
    
    
    else if(a+1 ==b){
        return 1.5;

    }
    else if(a==b){
        return 1;
    }                                                                
    
    
    return res;
    
}