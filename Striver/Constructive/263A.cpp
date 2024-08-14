// Problem link: https://codeforces.com/problemset/problem/263/A
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
    int center = 2;
    int oneRow, oneCol;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int x;
            cin >> x;
            if (x == 1) {
                oneRow = i;
                oneCol = j;
            } 
        }
    }
    cout << abs(oneRow - center) + abs(oneCol - center);
}