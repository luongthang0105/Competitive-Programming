#include <bits/stdc++.h>
using namespace std;

int f(int a, int b, int c, int n) {
    int lcm_ab = (a*b)/__gcd(a,b);
    int lcm_bc = (c*b)/__gcd(c,b);
    int lcm_ac = (a*c)/__gcd(a,c);

    if (lcm_ab == lcm_bc && lcm_bc == lcm_ac) return -1;
    
    int cnt = 0;
    int i = 1;
    while (cnt < n) {
        int div_cnt = (i % a == 0) + (i % b == 0) + (i % c == 0);
        if (div_cnt == 2) {
            cnt++;
        }
        i++;
    }
    return i;
}

int main() {
    // Providing a seed value
	srand((unsigned) time(NULL));
    // freopen("A.inp", "w", stdout);
    int numTests = 100;
    int boundNum = 1000;
    int boundN = 1000000;
    for (int i = 0; i < numTests; ++i) {
        int a = rand() % boundNum + 1;
        int b = rand() % boundNum + 1;
        int c = rand() % boundNum + 1;

        int n = rand() % boundN + 1;
        
        ofstream inp("A.inp");
        inp << a << " " << b << " " << c << " " << n;
        inp.close();
        system("./bruteA");
        system("./A");
        
        system("diff -w A.out A.ans");
        // if (system("diff -w A.out A.ans")) {
        //     cout << "Wrong answer test " << i + 1 << endl;
        // } else {
        //     cout << "Correct on test " << i + 1 << endl;
        // }
    }
}