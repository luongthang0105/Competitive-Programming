// Problem link: https://codeforces.com/contest/1291/problem/D
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
vector<vector<int>> charFreqs;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int n;
    string s;
    cin >> s;
    n = s.size();
    charFreqs.resize(n + 1, vector<int>(26, 0));

    for (int i = 0; i < n; ++i)
    {
        int c = s[i] - 'a';
        for (int k = 0; k < 26; ++k)
        {
            charFreqs[i + 1][k] = charFreqs[i][k] + (k == c);
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        if (l == r)
        {
            cout << "Yes" << endl;
            continue;
        }
        if (s[l - 1] != s[r - 1])
        {
            cout << "Yes" << endl;
            continue;
        }

        int numUniqueChars = 0;
        for (int k = 0; k < 26; ++k)
        {
            int cnt = charFreqs[r][k] - charFreqs[l - 1][k];
            if (cnt != 0)
            {
                numUniqueChars += 1;
            }
        }

        if (numUniqueChars >= 3)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}