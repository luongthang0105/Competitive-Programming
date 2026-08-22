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
    vector<int> lengths;
    int n;
    cin >> n;
    int sumL = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        lengths.push_back(x);
        sumL += x;
    }
    int minDiff = INT_MAX;
    int currSum = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        currSum += lengths[i];
        sumL -= lengths[i];
        minDiff = min(minDiff, abs(currSum - sumL));
    }
    cout << minDiff;
}