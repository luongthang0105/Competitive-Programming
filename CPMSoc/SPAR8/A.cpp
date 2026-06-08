#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<tuple<int, int, string>> scores;
    int i = 0;
    while (true)
    {
        string name;
        int score_f, score_l;
        cin >> name >> score_f >> score_l;
        if (name == "X" && score_f == 0 && score_l == 0)
        {
            break;
        }
        scores.push_back({score_l - score_f, i++, name});
    }
    sort(scores.begin(), scores.end());
    // reverse(scores.begin(), scores.end());
    for (auto &[score, _, name] : scores)
    {
        cout << name << " " << score << '\n';
    }
}