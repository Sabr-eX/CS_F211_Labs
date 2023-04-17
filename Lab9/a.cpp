#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 0;
    int ans = n;

    priority_queue<int, vector<int>, greater<int>> minheap;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        minheap.push(num);
        sum += num;

        if (sum < 0)
        {
            sum -= minheap.top();
            minheap.pop();
            ans--;
        }
    }

    cout << ans << endl;
}