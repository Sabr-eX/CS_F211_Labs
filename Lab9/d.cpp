#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    int cursum = 0;

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        cursum += (arr[i] - k);

        if (cursum == 0)
            ans++;

        if (freq.find(cursum) != freq.end())
            ans += freq[cursum];

        freq[cursum]++;
    }

    cout << ans;
}