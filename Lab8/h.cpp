#include <bits/stdc++.h>

using namespace std;

int main()
{
    string sent;
    cin >> sent;
    map<string, int> freq;
    for (int i = 0; i < sent.size() - 10; i++)
    {
        string key = "";
        for (int j = i; j < i + 10; j++)
        {
            key += sent[j];
        }

        if (freq.find(key) != freq.end())
        {
            freq[key]++;
        }
        else
        {
            freq[key] = 1;
        }
    }

    int ans = 0;
    for (auto i : freq)
    {
        if (i.second > 1)
        {
            ans++;
        }
    }
    cout << ans << endl;
    for (auto i : freq)
    {
        if (i.second > 1)
        {
            cout << i.first << endl;
        }
    }

    return 0;
}