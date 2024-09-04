// Problem link: https://codeforces.com/problemset/problem/2004/C
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

bool cmp(int a, int b) {
    return a > b;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        ll allSum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            allSum += a[i];
        }

        sort(a.begin(), a.end(), &cmp);
        ll bobSum = 0;
        for (int i = 1; i < n; i += 2) {
            allSum -= a[i];
            
            ll diff = a[i-1] - a[i];
            
            ll add = min(diff, k);
            a[i] += add;
            k -= add; 

            bobSum += a[i];
            allSum += a[i];
        }
        cout << (allSum - bobSum) - bobSum << endl;
    }
}