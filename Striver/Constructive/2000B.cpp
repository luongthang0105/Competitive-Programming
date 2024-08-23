// Problem link: https://codeforces.com/problemset/problem/2000/B
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
    while (t--) {
        int n;
        cin >> n;
        int leftPtr = 0;
        int rightPtr = 0;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (i == 0) {
                leftPtr = x - 1;
                rightPtr = x + 1;
            } else {
                if (x == leftPtr) leftPtr--;
                else if (x == rightPtr) rightPtr++;
                else ok = false;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}