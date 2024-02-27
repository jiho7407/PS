#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);
typedef complex<double> cpd;

void fft(vector<cpd> &a) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) {
            j -= bit;
        }
        j += bit;
        if (i < j) {
            swap(a[i], a[j]);
        }
        cout << j << " ";
    }
}

vector<cpd> A;
int main(){
    int N;
    cin >> N;
    int num;
    for(int i=0;i<N;i++){
        cin >> num;
        A.push_back(cpd(num, 0));
    }
    fft(A);
    cout << "\n";
    for(int i=0;i<N;i++){
        cout << A[i] << " ";
    }
}
