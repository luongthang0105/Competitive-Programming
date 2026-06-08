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

ll pairs(int x) {
    return (ll(x) * ll(x) + ll(x)) / 2;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int n;
    cin >> n;
    map<int, vector<int>> a, b;

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a[x].push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        b[x].push_back(i);
    }

    ll ans = 0;
    for (auto p : a) {
        int num = p.first;
        vector<int> indexesInA = p.second;
        vector<int> indexesInB = b[num];

        for (int indexA : indexesInA) {
            for (int indexB : indexesInB) {
                if (indexA == indexB) {
                    ans += (1 + pairs(indexA) + pairs(n - indexA - 1) + min(indexA, n - indexA - 1));
                } else {
                    int lowIdx = min(indexA, indexB);
                    int highIdx = max(indexA, indexB);

                    ans += min(lowIdx + 1, n - highIdx);
                }
            }
        }
    }
    cout << ans;
}