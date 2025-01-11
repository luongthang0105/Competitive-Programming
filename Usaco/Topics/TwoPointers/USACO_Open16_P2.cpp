// Problem link: 
#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "diamond" 
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;

const int maxn = 1e5 + 5;

struct Range {
    int start;
    int end;

    bool overlap(Range other) {
        return !(end < other.start || start > other.end);
    }

    int length() {
        return end - start + 1;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(prob".in", "r", stdin);freopen(prob".out", "w", stdout);
    int n, k;
    cin >> n >> k;

    vector<int> sizes(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> sizes[i];
    }
    sort(sizes.begin(), sizes.end());

    vector<int> leftSize(n, 0);
    vector<int> rightSize(n, 0);

    int left = 0, right = 0;
    while (right < n) {
        if (sizes[right] - sizes[left] <= k) {
            leftSize[right] = right - left + 1;
            if (right > 0) {
                leftSize[right] = max(leftSize[right], leftSize[right - 1]);
            }
            right += 1;
        } else {
            left++;
        }
    }
    
    

    left = n - 1, right = n - 1;
    while (left >= 0) {
        if (sizes[right] - sizes[left] <= k) {
            rightSize[left] = right - left + 1;
            if (left < n - 1) {
                rightSize[left] = max(rightSize[left], rightSize[left + 1]);
            }
            left -= 1;
        } else {
            right--;
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     cout << rightSize[i] << endl;
    // }

    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans = max(ans, leftSize[i] + rightSize[i + 1]);
    }
    cout << ans;
}

// sizes.push_back(INT_MAX);
// vector<Range> ranges;
// int start = 0, end = 0, prevEnd = 0;
// while (end < sizes.size()) {
//     if (sizes[end] - sizes[start] <= k) {
//         end += 1;
//     } else {
//         if (end - start != 1 && prevEnd != end) {
//             ranges.push_back({start, end - 1});
//             prevEnd = end;
//         }
//         start += 1;
//     }
// }

// int ans = 0;
// for (int i = 0; i < ranges.size(); ++i) {
//     if (ranges[i].length() == n) {
//         ans = n;
//         break;
//     } else {
//         ans = max(ans, ranges[i].length() + 1);
//     }
//     for (int j = i + 1; j < ranges.size(); ++j) {
//         if (ranges[i].overlap(ranges[j])) {
//             ans = max(ans, max(ranges[i].end, ranges[j].end) - min(ranges[i].start, ranges[j].start) + 1);
//         } else {
//             ans = max(ans, ranges[i].length() + ranges[j].length());
//         }
//     }
// // }
// cout << ans;