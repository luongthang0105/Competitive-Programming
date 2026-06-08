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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int i = 0;
    int j = n - 1;
    int turn = 0;
    vector<int> ans;
    while (i <= j)
    {
        if (turn == 0)
        {
            ans.push_back(a[j]);
            j -= 1;
            turn ^= 1;
        }
        else
        {
            ans.push_back(a[i]);
            i += 1;
            turn ^= 1;
        }
    }
    for (int i : ans)
    {
        cout << i << " ";
    }
}