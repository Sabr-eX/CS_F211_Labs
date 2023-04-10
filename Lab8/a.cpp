#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<string, int> freq;

    for (int i = 0; i < n; i++)
    {
        sort(a[i].begin(), a[i].end());
        freq[a[i]]++;
    }
    int ans = 0;
    for (auto x : freq)
    {
        int h = x.second;
        ans += (h * (h - 1)) / 2;
    }
    cout << ans << endl;
    return 0;
}