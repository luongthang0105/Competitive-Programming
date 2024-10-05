// Problem link: https://www.facebook.com/codingcompetitions/hacker-cup/2023/round-2/problems/A1
#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "B" 
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<db, db> pii;
typedef vector<ll> vll;

const int maxn = 1e7 + 5;
const double eps = 1e-9;
vector<bool> primes(maxn);
vector<int> cnt(maxn);
vector<int> added_primes;
void sieve() {
    fill(primes.begin(), primes.end(), true);
    primes[0] = primes[1] = false;
    for (int i = 2; i <= sqrt(maxn); ++i) {
        if (!primes[i]) continue;
        for (int j = i * i; j <= maxn; j += i) {
            primes[j] = false;
        }
    }
}

void preproc() {
    for (int i = 3; i <= 1e7 - 2; ++i) {
        if (primes[i] && primes[i + 2]) {
            added_primes.push_back(i + 2);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen(prob"_final.txt", "r", stdin);freopen(prob".txt", "w", stdout);
    int t;
    cin >> t;

    sieve();
    preproc();

    // for (int i = 0; i < 10; ++i) cout << added_primes[i] << " " << endl;

    for (int k = 1; k <= t; ++k) {
        int n;
        cin >> n;
        
        cout << "Case #" << k << ": ";
        if (n < 5) cout << 0;
        else cout << (upper_bound(added_primes.begin(), added_primes.end(), n) - added_primes.begin() + 1);
        cout << endl;
    }

}