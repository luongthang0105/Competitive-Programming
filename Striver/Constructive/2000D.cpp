// Problem link: https://codeforces.com/problemset/problem/2000/D
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
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (i != 0) a[i] += a[i - 1];
        }
        string s;
        cin >> s;
        ll sum = 0;
        int leftptr = 0;
        int rightptr = n - 1;
        // cout << s[2] << endl;
        while (leftptr < rightptr) {
            // cout << leftptr << " " << rightptr << endl;
            while (leftptr < n && s[leftptr] != 'L') leftptr++;
            while (rightptr >= 0 && s[rightptr] != 'R') rightptr--;

            if (leftptr < rightptr) {
                sum += (a[rightptr] - (leftptr == 0 ? 0LL : a[leftptr - 1]));
                leftptr++;
                rightptr--;
            }
        }
        cout << sum << endl;
    }
}