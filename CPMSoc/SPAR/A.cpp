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
vector<ll> sizes;
int n;
int m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> n >> m;
    sizes.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> sizes[i];
    }
    sort(sizes.begin(), sizes.end());

    if (m >= n)
    {
        cout << sizes.back();
        return 0;
    }

    int numPairs = n - m;
    int numSingle = m - numPairs;
    ll ans = 0;
    for (int i = 0; i < numPairs; ++i)
    {
        ans = max(ans, sizes[i] + sizes[numPairs * 2 - i - 1]);
        // cout << sizes[i] << "  " << sizes[numPairs * 2 - i - 1] << endl;
    }
    ans = max(ans, *max_element(sizes.begin() + numPairs * 2, sizes.end()));
    cout << ans;
}