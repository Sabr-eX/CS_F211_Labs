#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n = 0, q = 0;
    cin >> n >> q;
    map<int, int> mp;
    for (int i = 0; i < q; i++)
    {
        int t = 0, k = 0;
        cin >> t >> k;
        if (t == 1)
        {
            if (mp.find(k) == mp.end())
            {
                mp.insert(make_pair(k, 1));
            }
            else
            {
                mp.erase(k);
            }
        }
        else if (t == 2)
        {
            if (mp.lower_bound(k) == mp.end())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << mp.lower_bound(k)->first << endl;
            }
        }
        else
        {
            if (mp.find(k) == mp.end())
            {
                if (mp.upper_bound(k) == mp.begin())
                {
                    cout << -1 << endl;
                }
                else
                {
                    auto it = mp.upper_bound(k);
                    it--;
                    cout << it->first << endl;
                }
            }
            else
            {
                cout << mp.find(k)->first << endl;
            }
        }
    }
    return 0;
}