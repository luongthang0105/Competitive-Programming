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
vector<ll> sizes;
int a[100001];
pii b[100001];
int n;
int m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int temp;
    int index;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            cin >> a[j];
        }
        for (int j = 1; j <= n; j++)
        {
            cin >> b[j].first;
            int h =
                b[].second = j;
        }
        for (int k = 1; k <= n; k++)
        {
            if (a[k].first != b[k].first)
            {
                temp = b[k].first;
                index = b[k].second;
                m++;
            }
        }
        cout << m << '\n';
    }
}