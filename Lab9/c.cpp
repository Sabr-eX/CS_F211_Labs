#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    stack<int> stk;

    for (int i = 0; i <= n; i++)
    {
        while (!stk.empty() && (i == n || arr[stk.top()] >= arr[i]))
        {
            int mid = stk.top();
            stk.pop();
            int left = stk.empty() ? -1 : stk.top();

            ans -= arr[mid] * (i - mid) * (mid - left);
        }

        stk.push(i);
    }

    stk.pop();

    for (int i = 0; i <= n; i++)
    {
        while (!stk.empty() && (i == n || arr[stk.top()] <= arr[i]))
        {
            int mid = stk.top();
            stk.pop();
            int left = stk.empty() ? -1 : stk.top();

            ans += arr[mid] * (i - mid) * (mid - left);
        }

        stk.push(i);
    }

    cout << ans;
}