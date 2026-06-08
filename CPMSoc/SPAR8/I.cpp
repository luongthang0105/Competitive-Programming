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
    int n;
    cin >> n;
    vector<int> freqs(3);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j)
            cin >> freqs[j];
        int count_ones = 0;
        for (int j = 0; j < 3; ++j)
        {
            if (freqs[j] > 0)
            {
                freqs[j] -= 1;
                count_ones++;
            }
        }
        int count_twos = 0;
        sort(freqs.begin(), freqs.end());
        reverse(freqs.begin(), freqs.end());
        // cout << freqs[0] << endl;
        for (int j = 0; j < 3; ++j)
        {
            for (int k = j + 1; k < 3; ++k)
            {
                if (freqs[j] * freqs[k] != 0)
                {
                    count_twos += 1;
                    freqs[j] -= 1;
                    freqs[k] -= 1;
                }
            }
        }
        int count_threes = min({1, freqs[0], freqs[1], freqs[2]});

        cout << count_ones + count_twos + count_threes << '\n';
    }
}