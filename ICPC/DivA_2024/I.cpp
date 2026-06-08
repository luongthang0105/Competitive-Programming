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

bool is_palind(string &s)
{
    string temp = s;
    reverse(temp.begin(), temp.end());
    return temp == s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        string temp = s.substr(i, n);
        if (is_palind(temp))
        {
            cout << i;
            return 0;
        }
    }
}