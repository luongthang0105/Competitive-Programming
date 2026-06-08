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

int n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> n;
    queue<pair<char, int>> tasks;
    queue<int> OTasks;
    queue<int> BTasks;
    int posO = 1;
    int posB = 1;
    for (int i = 0; i < n; ++i)
    {
        char c;
        int pos;
        cin >> c >> pos;
        tasks.push({c, pos});
        if (c == 'O')
        {
            OTasks.push(pos);
        }
        else
        {
            BTasks.push(pos);
        }
    }
    int t = 0;
    while (!tasks.empty())
    {
        ++t;
        if (!OTasks.empty() && posO == OTasks.front())
        {
            if (tasks.front().first == 'O')
            {
                tasks.pop();
                OTasks.pop();

                if (!BTasks.empty() && posB != BTasks.front())
                {
                    if (posB < BTasks.front())
                    {
                        posB += 1;
                    }
                    else
                    {
                        posB -= 1;
                    }
                }
                continue;
            }
        }
        else if (!OTasks.empty() && posO != OTasks.front())
        {
            if (posO < OTasks.front())
            {
                posO += 1;
            }
            else
            {
                posO -= 1;
            }
        }

        if (!BTasks.empty() && posB == BTasks.front())
        {
            if (tasks.front().first == 'B')
            {
                tasks.pop();
                BTasks.pop();
            }
        }
        else if (!BTasks.empty() && posB != BTasks.front())
        {
            if (posB < BTasks.front())
            {
                posB += 1;
            }
            else
            {
                posB -= 1;
            }
        }
        // cout << t << ": " << "O=" << posO << "; B=" << posB << '\n';
    }
    cout << t;
}