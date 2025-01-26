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

int pairs(int x) {
    return (x * (x - 1) / 2);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        int ok = false;
        int numOnes, numNegOnes;
        for (int i = 0; i <= n / 2; ++i) {
            numOnes = i;
            numNegOnes = n - i;
            if (pairs(i) + pairs(n - i) == k) {
                ok = true;
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
            for (int i = 0; i < numOnes; ++i) cout << 1 << " ";
            for (int i = 0; i < numNegOnes; ++i) cout << -1 << " ";
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}