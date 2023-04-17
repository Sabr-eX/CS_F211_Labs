#include <bits/stdc++.h>
using namespace std;

bool comparator(string a, string b)
{
    string ab = a + b;
    string ba = b + a;

    if (ab > ba)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;

    string arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n, comparator);

    string ans = "";

    for (int i = 0; i < n; i++)
    {
        ans += arr[i];
    }

    cout << ans;
}