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

ll pairs(int x) {
    return (ll(x) * ll(x) + ll(x)) / 2;
}
vector<int> a, b;
unordered_map<int, vector<int>> aIndex;
unordered_map<int, vector<ll>> aPrefSum;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int n;
    cin >> n;


    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.pb(x);
    }

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        b.pb(x);
    }

    ll ans = 0;
    for (int i = 0; i < b.size(); ++i) {
        int rightPortion = n - i;
        int numB = b[i];

        int lowerBound = lower_bound(aIndex[b[i]].begin(), aIndex[b[i]].end(), rightPortion) - aIndex[b[i]].begin();

        if (lowerBound > 0) {
            ans += aPrefSum[b[i]][lowerBound - 1];
        }
        ans += (ll)rightPortion * ll(aIndex[b[i]].size() - lowerBound); 

        // update forward PrefSum
        aIndex[a[i]].push_back(i + 1);
        aPrefSum[a[i]].push_back(ll(i + 1));

        if (aPrefSum[a[i]].size() > 1) {
            aPrefSum[a[i]][aPrefSum[a[i]].size() - 1] += aPrefSum[a[i]][aPrefSum[a[i]].size() - 2];
        }
    }

    aIndex.clear();
    aPrefSum.clear();
    for (int i = b.size() - 1; i >= 0; --i) {
        int leftPortion = i + 1;
        int numB = b[i];

        int lowerBound = lower_bound(aIndex[b[i]].begin(), aIndex[b[i]].end(), leftPortion) - aIndex[b[i]].begin();

        if (lowerBound > 0) {
            ans += aPrefSum[b[i]][lowerBound - 1];
        }
        ans += (ll)leftPortion * ll(aIndex[b[i]].size() - lowerBound); 

        // update forward PrefSum
        aIndex[a[i]].push_back(n - i);
        aPrefSum[a[i]].push_back(ll(n - i));

        if (aPrefSum[a[i]].size() > 1) {
            aPrefSum[a[i]][aPrefSum[a[i]].size() - 1] += aPrefSum[a[i]][aPrefSum[a[i]].size() - 2];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            ans += 1 + pairs(i) + pairs(n - i - 1) + min(i, n - i - 1);
        }
    }
    
    // for (int i = 0; i < n; ++i) {
    //     int x; cin >> x;
    //     b[x].push_back(i);
    // }

    // ll ans = 0;
    // for (auto p : a) {
    //     int num = p.first;
    //     vector<int> indexesInA = p.second;
    //     vector<int> indexesInB = b[num];

    //     for (int indexA : indexesInA) {
    //         for (int indexB : indexesInB) {
    //             if (indexA == indexB) {
    //                 ans += (1 + pairs(indexA) + pairs(n - indexA - 1) + min(indexA, n - indexA - 1));
    //             } else {
    //                 int lowIdx = min(indexA, indexB);
    //                 int highIdx = max(indexA, indexB);

    //                 ans += min(lowIdx + 1, n - highIdx);
    //             }
    //         }
    //     }
    // }
    cout << ans;
}