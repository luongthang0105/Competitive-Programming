#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nTest; cin >> nTest;
    while (nTest--) {
        long long n;
        cin >> n;

        if(n % 16 != 0) {
            cout << 0;
        }
        else {
            n /= 16;
            long long x = sqrtl(n);
            if(x * x != n) {
                cout << 0;
            }
            else {
                int res = 0;
                for(long long i = 1; i * i <= x; ++i) {
                    if (x % i == 0) { 
                        ++res;
                        if (i != x / i) ++res;
                    }
                }
                cout << res;
            }
        }
        cout << '\n';
    }

    return 0;
}
