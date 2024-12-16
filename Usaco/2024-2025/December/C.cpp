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
int n, f;
string s;
// map<string, bool> res;
set<string> res;
unordered_map<string, int> cnt;

void process(string &s)
{
    for (int i = 0; i <= s.size() - 3; ++i)
    {
        if (!(s[i] != s[i + 1] && s[i + 1] == s[i + 2]))
            continue;
        string moo = s.substr(i, 3);
        if (res.find(moo) != res.end())
            continue;
        int count = 0;
        for (int j = i; j <= s.size() - 3; ++j)
        {
            if (s.substr(j, 3) == moo)
                count++;
        }
        if (count >= f)
            res.insert({moo, true});
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> n >> f;
    cin >> s;
    for (int i = 0; i <= s.size() - 3; ++i)
    {
        if (!(s[i] != s[i + 1] && s[i + 1] == s[i + 2]))
            continue;
        string moo = s.substr(i, 3);
        cnt[moo] += 1;
        // cout << moo << endl;
    }

    for (int i = 0; i < n; ++i)
    {
        char original = s[i];
        for (int j = 0; j < 26; ++j)
        {
            char new_c = j + 'a';
            bool ok = false;

            string tempF = "";
            string tempM = "";
            string tempL = "";

            string oldF = "";
            string oldM = "";
            string oldL = "";
            // first
            if (i < n - 2)
            {
                if (s[i + 1] == s[i + 2] && new_c != s[i + 1])
                {
                    tempF += new_c;
                    tempF += s[i + 1];
                    tempF += s[i + 2];
                    cnt[tempF] += 1;
                    ok = true;
                }
                oldF = s.substr(i, 3);
                // if (i == 2 && j == 14) cout << oldF;
                cnt[oldF] -= 1;
            }

            // middle
            if (i > 0 && i < n - 1)
            {
                if ((new_c == s[i + 1] && new_c != s[i - 1]))
                {
                    tempM += s[i - 1];
                    tempM += new_c;
                    tempM += s[i + 1];
                    cnt[tempM] += 1;
                    ok = true;
                }
                oldM = s.substr(i - 1, 3);
                cnt[oldM] -= 1;
            }

            // last
            if (i > 1)
            {
                if ((new_c == s[i - 1] && s[i - 1] != s[i - 2]))
                {
                    tempL += s[i - 2];
                    tempL += s[i - 1];
                    tempL += new_c;
                    cnt[tempL] += 1;
                    ok = true;
                }
                oldL = s.substr(i - 2, 3);
                cnt[oldL] -= 1;
            }
            if (ok)
            {
                for (auto p : cnt)
                {
                    if (p.second >= f)
                    {
                        // cout << i << " " << j << " " << p.first << endl;
                        res.insert(p.first);
                    }
                }
            }

            if (tempF != "")
            {
                cnt[tempF] -= 1;
            }
            if (tempM != "")
            {
                cnt[tempM] -= 1;
            }
            if (tempL != "")
            {
                cnt[tempL] -= 1;
            }
            if (oldF != "") cnt[oldF] += 1;
            if (oldM != "") cnt[oldM] += 1;
            if (oldL != "") cnt[oldL] += 1;
        }
        s[i] = original;
    }
    cout << res.size() << endl;
    for (auto p : res)
    {
        cout << p << '\n';
    }
}