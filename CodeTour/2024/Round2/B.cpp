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

bool isPrime(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    ll m;
    cin >> m;
    if (m == 2) {

    }
    string ans = "";
    for (ll i = 1LL; i <= sqrt(m); ++i) {
        if (m % i == 0) {
            // cout << i << " " << m/i << endl;
            if (i * i != m) {
                if (isPrime(m / i)) ans += alphabet[(m / i) % 26];
            }
            if (isPrime(i)) ans += alphabet[i % 26];
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans;
}