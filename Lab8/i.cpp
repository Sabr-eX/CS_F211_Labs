#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    map<int, int> loss;
    for (int i = 0; i < k; i++)
    {
        loss.insert({i + 1, 0});
    }

    while (n--)
    {
        int w, l;
        cin >> w >> l;
        loss[l]++;
    }

    for (int i = 0; i < k; i++)
    {
        if (loss[i + 1] < 2)
        {
            cout << i + 1 << " ";
        }
    }
    return 0;
}