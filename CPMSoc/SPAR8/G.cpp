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

int main()
{
    int players;
    cin >> players;
    pair<string, pair<int, int>> player_board[players];
    // Input palyer
    cin.ignore(1);
    for (int i = 0; i < players; i++)
    {
        cin >> player_board[i].first;
        player_board[i].second.first = 0;
        player_board[i].second.second = 0;
    }

    // Wonders
    for (int i = 0; i < players; i++)
    {
        int point;
        cin >> point;
        player_board[i].second.first += point;
    }

    // Military
    for (int i = 0; i < players; i++)
    {
        string temp;
        cin >> temp;
        int w, x, y, z;
        w = temp[1] - '0';
        x = temp[3] - '0';
        y = temp[5] - '0';
        z = temp[7] - '0';
        player_board[i].second.first += w + x * 3 + y * 5 + z * (-1);
    }

    // Civilian
    for (int i = 0; i < players; i++)
    {
        int point;
        cin >> point;
        player_board[i].second.first += point;
    }

    // Commercial
    for (int i = 0; i < players; i++)
    {
        int point;
        cin >> point;
        player_board[i].second.first += point;
    }

    // Science Cards
    for (int i = 0; i < players; i++)
    {
        string temp;
        cin >> temp;
        int a, b, c;
        a = (temp[1] - '0') * (temp[1] - '0');
        b = (temp[3] - '0') * (temp[3] - '0');
        c = (temp[5] - '0') * (temp[5] - '0');
        player_board[i].second.first += a + b + c;
        int num_set = min({(temp[1] - '0'), (temp[3] - '0'), (temp[5] - '0')});
        // num_set = min(num_set, c);
        player_board[i].second.first += num_set * 8;
    }

    // Coin
    for (int i = 0; i < players; i++)
    {
        int n;
        cin >> n;
        player_board[i].second.first += n / 3;
        player_board[i].second.second += n;
    }

    string bestP;
    // Output
    for (pair<string, pair<int, int>> x : player_board)
    {
        cout << x.first << "'s total score: " << x.second.first << endl;
    }
    stable_sort(player_board, player_board + players, [](const pair<string, pii> &a, const pair<string, pii> &b)
                { if (a.second.first == b.second.first) {
                    return a.second.second < b.second.second;
                }
                return a.second.first < b.second.first; });
    vector<string> bests;
    bests.push_back(player_board[players - 1].first);
    for (int i = players - 2; i >= 0; --i)
    {
        if (player_board[i].second == player_board[players - 1].second)
        {
            bests.push_back(player_board[i].first);
        }
        else
        {
            break;
        }
    }
    reverse(bests.begin(), bests.end());
    if (bests.size() > 1)
    {
        cout << "Winners: ";
        for (auto s : bests)
        {
            cout << s << " ";
        }
    }
    else
    {
        cout << "Winner: ";
        cout << bests.back();
    }
}