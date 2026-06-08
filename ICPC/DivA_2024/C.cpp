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
const double EPS = 1e-9;
vector<double> pots, swords;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    double h;
    int n, m, L;
    cin >> h >> n >> m >> L;
    pots.resize(n);
    swords.resize(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> pots[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> swords[i];
    }
    sort(pots.begin(), pots.end());
    sort(swords.begin(), swords.end());

    reverse(pots.begin(), pots.end());
    reverse(swords.begin(), swords.end());

    double ans = LLONG_MAX;
    for (int i = 0; i <= n; ++i)
    {
        int numpots = i;
        int numswords = min(L - i, m);
        double curr_hp = h;
        for (int j = 0; j < numpots; ++j)
        {
            curr_hp -= pots[j] * curr_hp / 100.0;
        }

        for (int j = 0; j < numswords; ++j)
        {
            curr_hp -= swords[j];
        }

        ans = min(ans, curr_hp);
    }
    cout << fixed << setprecision(10) << ans;
}