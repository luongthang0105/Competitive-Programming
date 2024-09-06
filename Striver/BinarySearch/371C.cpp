// Problem link: https://codeforces.com/contest/371/problem/C 
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

ll nB, nS, nC;
ll rB, rS, rC;
ll r;
unordered_map<char, ll> countIngredients;

bool makable(ll numBurgers) {
    // cout << numBurgers << endl;
    ll totalB = numBurgers * countIngredients['B'];
    ll totalS = numBurgers * countIngredients['S'];
    ll totalC = numBurgers * countIngredients['C'];

    ll bNeed = totalB - nB;
    ll sNeed = totalS - nS;
    ll cNeed = totalC - nC;

    // cout << "bneed: " << bNeed << endl;
    // cout << "sneed: " << sNeed << endl;
    // cout << "cneed: " << cNeed << endl;
    ll dummyR = r;

    if (bNeed > 0) {
        dummyR -= bNeed * rB;    
    }
    if (sNeed > 0) {
        dummyR -= sNeed * rS;    
    }
    if (cNeed > 0) {
        dummyR -= cNeed * rC;    
    }

    // cout << "final r: " <<  dummyR << endl;
    return dummyR >= 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    string s;
    cin >> s;
    for (char c : s) {
        countIngredients[c] += 1;
    }
    cin >> nB >> nS >> nC;
    cin >> rB >> rS >> rC;
    cin >> r;

    ll low = 0, high = r + nB + nS + nC;
    ll ans = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (makable(mid)) {
            low = mid + 1;
            ans = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << ans;
}