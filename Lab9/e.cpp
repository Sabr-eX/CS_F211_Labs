#include <bits/stdc++.h>
using namespace std;

#define ppi pair<int, int>, int >>

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int n;
    cin >> n;

    map<int, map<pair<int, int>, int>> matA;

    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        matA[y][{x, y}] = z;
    }

    map<pair<int, int>, int> ans;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        for (auto it : matA[x])
        {
            ans[{it.first.first, y}] += z * it.second;
        }
    }

    int cnt = 0;

    for (auto x : ans)
        cnt++;

    cout << cnt << endl;

    for (auto x : ans)
    {
        cout << x.first.first << " " << x.first.second << " " << x.second << endl;
    }
}