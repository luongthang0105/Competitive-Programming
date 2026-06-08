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

unordered_map<char, int> bindings = {
    {'a', 2},
    {'b', 2},
    {'c', 2},

    {'d', 3},
    {'e', 3},
    {'f', 3},

    {'g', 4},
    {'h', 4},
    {'i', 4},

    {'j', 5},
    {'k', 5},
    {'l', 5},

    {'m', 6},
    {'n', 6},
    {'o', 6},

    {'p', 7},
    {'q', 7},
    {'r', 7},
    {'s', 7},

    {'t', 8},
    {'u', 8},
    {'v', 8},

    {'w', 9},
    {'x', 9},
    {'y', 9},
    {'z', 9},
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int n, m;
    cin >> n >> m;
    unordered_map<string, set<string>> phone_map;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        string num_rep = "";
        for (char c : s)
        {
            num_rep += to_string(bindings[c]);
        }
        phone_map[num_rep].insert(s);
    }
    for (int i = 0; i < m; ++i)
    {
        string phone;
        cin >> phone;
        if (phone_map.contains(phone))
        {
            cout << phone_map[phone].size() << " ";
            for (string w : phone_map[phone])
            {
                cout << w << " ";
            }
        }
        else
        {
            cout << 0;
        }
        cout << '\n';
    }
}