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
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    string s;
    cin >> s;
    if (s.size() < 2) {
        cout << s;
    } else {
        if (s[1] >= '5') {
            if (s[0] == '9') {
                cout << 10;
            } else {
                int c = s[0] - '0';
                cout << c + 1;
            }
        } else {
            cout << s[0];
        }
        for (int i = 1; i < s.size(); ++i) cout << 0;
    }
}