#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const double PI =  acos(-1);
void FFT(vector<complex<double>> &f, complex<double> w){
    int n = f.size();
    if(n==1) return;

    vector<complex<double>> even(n/2), odd(n/2);
    for(int i = 0; i<n; i++){
        if(i%2) odd[i/2] = f[i];
        else even[i/2] = f[i];
    }

    FFT(odd, w*w); FFT(even, w*w);

    complex<double> wp(1, 0);
    for(int i = 0; i<n/2; i++){
        f[i] = even[i] + wp*odd[i];
        f[i+n/2] = even[i] - wp*odd[i];
        wp *= w;
    }
}

vector<complex<double>> mul(vector<complex<double>> a, vector<complex<double>> b){
    int n = 1;
    while(true){
        if(n >= a.size() and n >= b.size()) break;
        n *= 2;
    }
    n *= 2;
    a.resize(n);
    b.resize(n);
    vector<complex<double>> c(n);
    complex<double> w(cos(2*PI/n), sin(2*PI/n));

    FFT(a, w);
    FFT(b, w);

    for(int i = 0; i<n; i++){
        c[i] = a[i]*b[i];
    }
    FFT(c, complex<double>(1,0)/w);
    for(int i = -0; i<n; i++){
        c[i] /= complex<double> (n, 0);
        c[i] = complex<double>(round(c[i].real()), round(c[i].imag()));
    }
    return c;
}

int main(){
    string A, B;
    cin >> A >> B;
    vector<complex<double>> AV, BV, CV;
    for(int i=0; i < A.length(); i++){
        AV.push_back(complex<double>(A[i] - '0', 0));
    }
    for(int i=0; i < B.length(); i++){
        BV.push_back(complex<double>(B[i] - '0', 0));
    }
    reverse(AV.begin(), AV.end());
    reverse(BV.begin(), BV.end());
    CV = mul(AV, BV);
    int Clen = A.length() + B.length();
    int ans[Clen];
    fill(ans, ans+Clen, 0);
    for(int i=0; i < CV.size(); i++){
        int cmd = round(CV[i].real());
        int idx = i;
        while(cmd){
            ans[idx] += cmd%10;
            if(ans[idx]>=10){
                ans[idx+1] += ans[idx]/10;
                ans[idx] %= 10;
            }
            cmd /= 10;
            idx++;
        }
    }
    reverse(ans, ans+Clen);
    bool startzero = true;
    for(int i = 0; i<Clen; i++){
        if(startzero && ans[i] == 0) continue;
        else startzero = false;
        cout << ans[i] << "";
    }
    if(startzero) cout << 0;
}