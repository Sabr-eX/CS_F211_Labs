#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    pair<int, int> arr[n];
    for (int i = 0; i < n; i++)
    {
        int a, d;
        cin >> a >> d;
        arr[i] = {a, d};
    }

    sort(arr, arr + n);

    priority_queue<int, vector<int>, greater<int>> minheap;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        while (!minheap.empty() && arr[i].first > minheap.top())
        {
            minheap.pop();
        }

        minheap.push(arr[i].second);
        int a = minheap.size();
        ans = max(ans, a);
    }

    cout << ans << endl;
}