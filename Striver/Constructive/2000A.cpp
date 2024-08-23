// Problem link: https://codeforces.com/problemset/problem/2000/A
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
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s.size() <= 2) {
            cout << "NO";
        }
        else if (s[0] == '1' && s[1] == '0') {
            if (s[2] == '0' || (s[2] == '1' && s.size() == 3)) {
                cout << "NO";
            } else {
                cout << "YES";
            }
        } else {
            cout << "NO";
        }
        cout << endl;
    }
}