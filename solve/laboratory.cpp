#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const long long pow10[] = {1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;

    int p = 0, q = 1;
    {
        bool flag = false;
        for (const char &c: s) {
            if (c == '.') {
                flag = true;
            } else {
                p = p * 10 + (c - '0');
                if (flag) { q *= 10; }
            }
        }
    }

    bool flag = false;
    vector<int> ans;
    for (int d = 1; d <= 8; d++) {
        long long k = pow10[d - 1];
        for (int a = 1; a <= 9; a++) {
            if(10 * q == p) { break; }
            long long b = (p * k - q) * a / (10 * q - p);
            if (b >= k) { continue; }
            if (p * (k * a + b) == q * (10 * b + a)) {
                flag = true;

                if(d == 1) {
                    cout << a << '\n';
                } else {
                    cout << a << setfill('0') << setw(d - 1) << b << '\n';
                }
            }
        }
    }

    if (!flag) {
        cout << "No solution";
    }
    return 0;
}