// Problem link: https://codeforces.com/problemset/problem/514/A
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
    string x;
    cin >> x;
    for (int i = 0; i < x.size(); ++i) {
        int c = x[i] - '0';
        if ((i == 0 && c == 9) || 9 - c > c) {
            cout << c;
        }
        else {
            cout << 9 - c;
        }
    }
}