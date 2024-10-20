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

ll dp[19][2][11][11][20];

const int LIM_ERROR = 10;
const int POS_ERROR = 19;

bool isMiddle(int start, int pos, int size) {
    return int((size - start) / 2) == pos - start;
}
ll M;
// need to check odd number of digits, by checking startPost
ll recursive(int pos, bool smaller, int least, int most, int startPos, vector<int>& digits, vector<char> newDigits) {
    // cout << "pos: " << pos << " digit size: " << digits.size() << endl;
    // for (char c : newDigits) cout << c;
    // cout << endl;
    if (pos == digits.size()) {
        string str = "";
        for (char c : newDigits) str += c;
        if (stoll(str) % M == 0 && stoll(str) != 0) {
            cout << str << endl;
            return 1;
        }
        return 0;
        cout << "hii";
    }

    if (dp[pos][smaller][least][most][startPos] != -1) {
        return dp[pos][smaller][least][most][startPos];
    }

    int limit = 0;
    if (smaller == 0) {
        limit = digits[pos];
    } else {
        limit = 9;
    }

    ll res = 0;
    ll starter = 0;
    if (startPos != POS_ERROR) starter = 1;
    if (least != LIM_ERROR) starter = least;
    else limit = min(limit, most);

    for (int digit = starter; digit <= limit; ++digit) {
        int newSmaller = smaller;

        if (smaller == 0 && digit < limit) newSmaller = 1;

        // mark the start position => make middle unique and check odd size
        if (startPos == POS_ERROR && digit != 0) {
            startPos = pos;

            // check odd size
            if ((digits.size() - startPos) % 2 == 0) {
                continue; //could be break?
            }
        }

        // if havent got startPos, then just let least = digit
        // if next position is middle, then we need to make least == digit + 1 (for middle to be unique)
        // if current position is middle, then we need to make least == -1, most = digit
        newDigits.pb(digit + '0');
        if (startPos == POS_ERROR) {
            res += recursive(pos + 1, newSmaller, digit, most, startPos, digits, newDigits);        
        } else if (isMiddle(startPos, pos + 1, digits.size())) {
            res += recursive(pos + 1, newSmaller, digit + 1, most, startPos, digits, newDigits);        
        } else if (isMiddle(startPos, pos, digits.size())) {
            res += recursive(pos + 1, newSmaller, LIM_ERROR, digit, startPos, digits, newDigits);
        }
        newDigits.pop_back();
    }

    return dp[pos][smaller][least][most][startPos] = res;
}

vector<int> getDigits(ll n) {
    vector<int> temp;
    while (n > 0) {
        temp.pb(n % 10);
        n /= 10;
    }
    reverse(temp.begin(), temp.end());
    return temp;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen(prob"_final.txt", "r", stdin);freopen(prob".txt", "w", stdout);
    
    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k) {
        ll A, B;
        cin >> A >> B >> M;

        memset(dp, -1, sizeof(dp));
        vector<int> digitsA = getDigits(max(A - 1, 0LL));
        vector<int> digitsB = getDigits(B);

        ll ansA = A == 0 ? 0 : recursive(0, 0, 0, LIM_ERROR, POS_ERROR, digitsA, vector<char>());

        // cout << digitsB.size() << endl;
        ll ansB = recursive(0, 0, 0, LIM_ERROR, POS_ERROR, digitsB, vector<char>());

        cout << "ansA: " << ansA << endl;
        cout << "ansB: " << ansB << endl;
        cout << "Case #" << k << ": ";
        cout << ansB - ansA;
        cout << endl;
    }

}