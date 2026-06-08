#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    cin.ignore(1);
    string s;
    while (n--)
    {
        getline(cin, s);
        int start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ' || i == s.size() - 1)
            {
                int end = i;
                if (i == s.size() - 1)
                {
                    end++;
                }
                string temp;
                for (int j = start; j < end; j++)
                {
                    temp.push_back(s[j]);
                }
                start = i + 1;

                if (temp.size() >= 4)
                {
                    cout << temp[0];
                    for (int k = temp.size() - 2; k >= 1; k--)
                    {
                        cout << temp[k];
                    }

                    cout << temp[temp.size() - 1] << " ";
                }
                else
                {
                    cout << temp << " ";
                }
            }

            if (i == s.size() - 1)
            {
                cout << endl;
            }
        }
    }

    return 0;
}
