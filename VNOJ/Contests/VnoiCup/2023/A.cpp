// Problem link: https://oj.vnoi.info/problem/vnoicup23_r1_a
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

map<int, int> rela;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            int a; cin >> a;
            rela[i] = a;
        }

        bool ok = false;
        // cout << rela[rela[1]] << endl;
        for (int i = 1; i <= n; ++i) {
            if (rela[rela[rela[i]]] == i) {
                ok = true;
                break;
            }
        }

        if (ok) cout << "<3";
        else cout << "</3";
        cout << endl;
    }
}