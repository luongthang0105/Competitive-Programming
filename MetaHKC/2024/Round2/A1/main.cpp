// Problem link: https://www.facebook.com/codingcompetitions/hacker-cup/2023/round-2/problems/A1
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
typedef pair<db, db> pii;
typedef vector<ll> vll;

const int maxn = 1e5 + 5;

const double eps = 1e-9;

vector<ll> possibles;

void genPossible() {
    int digits = 1; 
    for (; digits < 19; digits += 2) {
        int numFirstHalf = ceil(digits / 2.0);
        bool stop = 0;
        // cout << "digits: " << digits << endl;
        // cout << "numFirstHalf: " << numFirstHalf << endl;
        for (int starter = 1;; starter++) {
            string str = "";
            // cout << "starter: " << starter << endl;
            if (starter + numFirstHalf - 1 > 9) {
                stop = 1;
                break;
            }
            int counter = starter;
            for (int i = 1; i <= numFirstHalf; ++i, counter++) {
                str += counter + '0';
            }
            counter -= 2;
            for (int i = 1; i < numFirstHalf; ++i, counter--) {
                str += counter + '0';
            }
            // cout << str << endl;
            possibles.pb(stoll(str));
        }
    }

    // for (ll i : possibles) cout << i << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(prob"_final.txt", "r", stdin);freopen(prob".txt", "w", stdout);
    
    genPossible();
    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k) {
        ll A, B, M;
        cin >> A >> B >> M;
        ll counter = 0;
        for (ll num : possibles) {
            if (A <= num && num <= B && num % M == 0) {
                counter++;
            }
        }
        cout << "Case #" << k << ": ";
        cout << counter;
        cout << endl;
    }

}