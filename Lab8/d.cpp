#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, q;
    cin >> n >> q;
    long long a[n] = {0};
    map<long long, long long> indexes;
    while (q--)
    {
        long long t, k;
        cin >> t >> k;
        if (t == 1)
        {
            a[k] = 1 - a[k];
            if (a[k] == 1)
            {
                indexes.insert({k, 1});
            }
            else
            {
                indexes.erase(k);
            }
        }

        else if (t == 2)
        {
            cout << (*indexes.upper_bound(k)).first << endl;
        }
        else if (t == 3)
        {
            cout << (*indexes.lower_bound(k)).first << endl;
        }
    }

    return 0;
}