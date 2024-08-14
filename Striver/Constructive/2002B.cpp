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

bool check(int aS, int aE, int bS, int bE) {
    set<int> s {aS, aE, bS, bE};
    return s.size() == 2;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a, b;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            b.push_back(x);
        }

        int aStart = 0, aEnd = n - 1;
        int bStart = 0, bEnd = n - 1;
        bool aliceWon = false;
        while ((aStart < aEnd) && (bStart < bEnd)) {
            if ((a[aStart] != b[bStart] && a[aStart] != b[bEnd])
            ||  (a[aEnd] != b[bStart] && a[aEnd] != b[bEnd])) {
                aliceWon = true;
                break;
            }
            if (a[aStart] == b[bStart]) {
                aStart++;
                bStart++;
            } else if (a[aStart] == b[bEnd]) {
                aStart++;
                bEnd--;
            } else if (a[aEnd] == b[bStart]) {
                aEnd--;
                bStart++;
            } else if (a[aEnd] == b[bEnd]) {
                aEnd--;
                bEnd--;
            }
            // cout << "As: " << aStart << " " << aEnd << endl;
            // cout << "Bs: " << bStart << " " << bEnd << endl;

        }
        if (aliceWon) {
            cout << "Alice";
        } else {
            cout << "Bob";
        }
        cout << endl;
    }
}