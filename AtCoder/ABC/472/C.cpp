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
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> cals(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> cals[i];
    }

    ll sumCals = 0;
    queue<int> lastMDays;
    for (int i = 0; i < n; ++i)
    {
        if (!lastMDays.empty() && lastMDays.front() < i - m + 1)
        {
            sumCals -= cals[lastMDays.front()];
            lastMDays.pop();
        }

        if (sumCals + cals[i] > k)
        {
            cout << "No";
        }
        else
        {
            cout << "Yes";
            sumCals += cals[i];
            lastMDays.push(i);
        }
        cout << '\n';
    }
}