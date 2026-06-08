#include <bits/stdc++.h>
using namespace std;
long long n;
double arr[101];
int arr_1[101];
long long total = 0;
double total_1 = 0;
long long pay = 0;
double pay_1 = 0;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr_1[i] = arr[i] * 100;
        pay_1 += arr[i];
        pay += arr_1[i];
    }
    cin >> total_1;
    total = total_1 * 100;
    double total_price = pay_1;
    if ((pay % 10) <= 4 && (pay % 10) >= 1)
    {
        pay = pay - pay % 10;
    }
    else if ((pay % 10) >= 5 && (pay % 10) <= 9)
    {
        pay = pay + 10 - pay % 10;
    }
    double rounded_price = pay;
    int ans = total - pay;
    double result = ans / 100;
    cout << "Total price: $" << fixed << setprecision(2) << total_price << '\n';
    cout << "Rounded price: $" << fixed << setprecision(2) << rounded_price << '\n';
    cout << "Change: $" << fixed << setprecision(2) << result << '\n';
}