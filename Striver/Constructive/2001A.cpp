// Problem link: https://codeforces.com/problemset/problem/2001/A
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
        map<int,int> count;
        int n;
        cin >> n;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            count[x]++;
            mx = max(mx, count[x]);
        }
        cout << n - mx << endl;
    }
}