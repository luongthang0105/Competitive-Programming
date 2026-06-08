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

int get_point(string s)
{
    int point = 0;
    for (int i = 1; i < s.size(); i++)
    {
        int digit = s[i] - '0';
        point *= 10;
        point += digit;
    }

    if (s[0] == 'D')
    {
        point += point;
    }
    else if (s[0] == 'T')
    {
        point += point * 2;
    }
    return point;
}

int main()
{
    // Input player name
    pair<string, int> players[2];
    cin >> players[0].first >> players[1].first;
    players[0].second = 0;
    players[1].second = 0;

    cin.ignore(1);
    bool is_finished = false;
    int turn = 0;
    while (1)
    {
        string d1;
        cin >> d1;
        if (d1 == "END")
        {
            break;
        }
        string d2, d3;
        cin >> d2 >> d3;
        turn++;

        // Count points in the turn
        bool is_last_double = false;
        int point = get_point(d1);
        point += get_point(d2);
        point += get_point(d3);

        if (d3 != "0" && d3 != "X")
        {
            is_last_double = d3[0] == 'D';
        }
        else if (d2 != "0" && d2 != "X")
        {
            is_last_double = d2[0] == 'D';
        }
        else if (d1 != "0" && d1 != "X")
        {
            is_last_double = d1[0] == 'D';
        }

        int player_turn = 0;
        if (turn % 2 == 0)
        {
            player_turn = 1;
        }

        if (players[player_turn].second + point == 501)
        {
            if (is_last_double)
            {
                cout << players[player_turn].first << " has won.\n";
                is_finished = true;
            }
        }
        else if (players[player_turn].second + point > 499)
        {
            continue;
        }
        else if (players[player_turn].second + point <= 499)
        {
            players[player_turn].second += point;
        }
    }

    if (!is_finished)
    {
        cout << players[0].first << " needs " << 501 - players[0].second << ".\n";
        cout << players[1].first << " needs " << 501 - players[1].second << ".\n";

        if (turn % 2 != 0)
        {
            cout << players[1].first << " to throw next.\n";
        }
        else
        {
            cout << players[0].first << " to throw next.\n";
        }
    }
}