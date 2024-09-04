// Problem link: https://codeforces.com/problemset/problem/2004/B
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

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        int l, r;
        int L, R;
        cin >> l >> r;
        cin >> L >> R;

        if (r < L || l > R) {
            cout << 1;
        } else {
            int iS = max(l, L);
            int iE = min(r, R);
            int outerL = min(l, L);
            int outerR = max(r, R);

            cout << iE - iS + (iS - 1 >= outerL) + (iE + 1 <= outerR);
        }
        cout << endl;
    }
}