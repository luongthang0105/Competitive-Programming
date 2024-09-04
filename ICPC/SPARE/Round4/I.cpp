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
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int n; 
    int x;
    cin >> n >> x;
    if (n == 1) {
        cout << x;
        return 0;
    }
    vector<int> finalCoeff(2, 1);
    for (int i = 3; i <= n; ++i) {
        vector<int> newCoeff;
        newCoeff.pb(finalCoeff.front());
        for (int j = 0; j < finalCoeff.size() - 1; ++j) {
            newCoeff.pb(finalCoeff[j] + finalCoeff[j + 1]);
        }
        newCoeff.pb(finalCoeff.back());
        finalCoeff = newCoeff;
    }

    int rhsSum = 0;
    for (int i = 1; i < finalCoeff.size(); ++i) {
        rhsSum += finalCoeff[i];
        // cout << finalCoeff[i] << " ";
    }
    int lhs = x - rhsSum;
    if (lhs < 1) {
        cout << "impossible" << endl;
    } else {
        vector<vector<int>> ans;
        vector<int> finalRow(n, 1);
        finalRow[0] = lhs;
        ans.pb(finalRow);
        for (int i = 0; i < n; ++i) {
            vector<int> lastRow = ans.back();
            vector<int> nextRow;
            for (int j = 0; j < lastRow.size() - 1; ++j) {
                nextRow.pb(lastRow[j] + lastRow[j + 1]);
            }
            ans.pb(nextRow);
        }
        for (int i = ans.size() - 1; i >= 0; --i) {
            for (int j : ans[i]) cout << j << " ";
            cout << endl;
        }
    }
}