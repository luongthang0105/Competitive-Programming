// Problem link: https://www.facebook.com/codingcompetitions/hacker-cup/2023/round-2/problems/A1
#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "A" 
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<db, db> pii;
typedef vector<ll> vll;

const int maxn = 1e5 + 5;

const int dx[4] = {0, 1, -1, 0};
const int dy[4] = {1, 0,  0,-1};

const double eps = 1e-9;

bool ok(db speed, vector<pii> intervals) {
    double index = 1.0;
    // cout << "speed: " << speed << endl;
    for (pii p : intervals) {
        // cout << speed * p.first << " " << index << " " << speed * p.second << endl;

        if (!(speed * p.first <= index && index <= speed * p.second)) {
            return false;
        }
        index++;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(prob"_final.txt", "r", stdin);freopen(prob".txt", "w", stdout);
    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k) {
        int n;
        cin >> n;
        vector<pii> a(n);

        db l = 0, r = 1e6;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
            
            l = max((i + 1) / a[i].second, l);
            r = min((i + 1) / a[i].first, r);
        }

        

        // while (r - l >= eps) {
        //     db m1 = l + (r - l) / 3;
        //     db m2 = r - (r - l) / 3;

        //     bool f1 = ok(m1, a);
        //     bool f2 = ok(m2, a);

        //     cout << "m1: " << m1 << "->" << f1 << endl;
        //     cout << "m2: " << m2 << "->" << f2 << endl;
        //     if (f1 && f2) {
        //         r = m2;
        //         ans = m1;
        //     } else if (!f1 && f2) {
        //         l = m1;
        //     } else if (f1 && !f2) {
        //         r = m2;
        //     } else if (!f1 && !f2) {
        //         l = m1;
        //         r = m2;
        //     }
        // }
        cout << "Case #" << k << ": ";
        if (l <= r) {
            cout << l;
        } else cout << -1;
        cout << endl;
    }

}