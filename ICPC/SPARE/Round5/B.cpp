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

vector<char> chars = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int y;
    cin >> y;
    string w1, w2, w3;
    cin >> w1 >> w2 >> w3;

    for (int i = 2; i <= 16; ++i)
    {
        int temp_year = y;
        vector<int> rems;
        while (temp_year > 0)
        {
            rems.push_back(temp_year % i);
            temp_year /= i;
        }
        if ((rems.size() > 2) && (rems[0] == 0) && (rems[1] == 0))
        {
            cout << i << " ";
            reverse(rems.begin(), rems.end());
            for (int j : rems)
            {
                cout << chars[j];
            }
            return 0;
        }
    }
    cout << "impossible";
}