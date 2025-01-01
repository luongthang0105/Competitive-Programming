// Problem link: https://codeforces.com/contest/1398/problem/C
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
        vector<int> a(n+5, 0);
        for (int i = 1; i <= n; ++i) {
            char x; cin >> x;
            a[i] = x - '0';
            if (i > 1) {
                a[i] += a[i - 1];
            }
        }
        map<int, ll> cnt;
        cnt[0] = 1;
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += cnt[a[i] - i];
            cnt[a[i] - i] += 1;
        }
        cout << ans << endl;
    }
}