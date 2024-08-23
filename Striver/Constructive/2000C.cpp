// Problem link: https://codeforces.com/problemset/problem/2000/C
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
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int k;
        cin >> k;
        for (int i = 0; i < k; ++i) {
            string s;
            cin >> s;
            if (s.size() != n) {
                cout << "NO" << endl;
                continue;
            }
            unordered_map<int, char> fw;
            unordered_map<char, int> bw;
            bool ok = true;
            for (int j = 0; j < s.size(); ++j) {
                char c = s[j];
                int temp = a[j];

                if (fw.find(temp) == fw.end() && bw.find(c) == bw.end()) {
                    fw[temp] = c;
                    bw[c] = temp;
                } else if (fw.find(temp) != fw.end() && bw.find(c) != bw.end()) {
                    if (fw[temp] != c || bw[c] != temp) {
                        ok = false;
                        break;
                    }
                } else {
                        // cout << "Went here " << j;
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}