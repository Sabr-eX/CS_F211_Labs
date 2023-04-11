#include <bits/stdc++.h>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // We hash each word into letters + number and store it in map
    map<string, int> store;

    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;

        // Initialize letters to 0
        int letters[26] = {0};
        // This gives us time complexity of O(m)
        for (char t : word)
        {
            letters[t - 'a']++;
        }

        // This hashes the words -> O(26)
        string key = "";
        for (int i = 0; i < 26; i++)
        {
            key += ('a' + i);
            key += to_string(letters[i]);
        }

        // Adds into map O(logn)
        if (store.find(key) == store.end())
        {
            store[key] = 1;
        }
        else
        {
            store[key]++;
        }
    }
    // This loop runs n times so, TC = mn + 26n + nlogn

    // This loop goes through all distinct elements only
    int answer = 0;
    for (auto x : store)
    {
        answer += (x.second) * (x.second - 1) / 2;
    }
    cout << answer << endl;

    cout << "--------- END TEST CASE "
         << " ---------" << endl;
    return 0;
}
