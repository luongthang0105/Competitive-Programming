// Problem link: 
#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "main" 
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;

const int maxn = 1e5 + 5;

int rand(int start, int end) {
    return (rand() % (end - start + 1)) + start;
}
int main(int argc, char* argv[])
{
    srand(atoi(argv[1]));

    int n = rand(2, 6);
    set<int> usedX;
    set<int> usedY;
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        int x, y;
        do {
            x = rand(1, 10);
        } while (usedX.count(x));
        
        do {
            y = rand(1, 10);
        } while (usedY.count(y));

        cout << x << " " << y << endl;
        
        usedX.insert(x);
        usedY.insert(y);
    }
}