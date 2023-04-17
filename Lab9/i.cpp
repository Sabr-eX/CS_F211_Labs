#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int gas[n];
    int cost[n];

    int gasTotal = 0;
    int costTotal = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> gas[i];
        gasTotal += gas[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
        costTotal += cost[i];
    }

    if (gasTotal < costTotal)
    {
        cout << -1 << endl;
        return 0;
    }

    int total = 0, res = 0;

    for (int i = 0; i < n; i++)
    {
        total += gas[i] - cost[i];

        if (total < 0)
        {
            total = 0;
            res = i + 1;
        }
    }

    cout << res;
}