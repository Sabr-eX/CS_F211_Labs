#include <iostream>
#include <stack>
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

    stack<int> stk;
    stk.push(-1);
    int max_area = 0;

    for (int i = 0; i < n; i++)
    {
        while (stk.top() != -1 and arr[stk.top()] >= arr[i])
        {
            int current_height = arr[stk.top()];
            // cout << current_height << " ";
            stk.pop();
            int current_width = i - stk.top() - 1;
            // cout << current_width << " ";
            max_area = max(max_area, current_height * current_width);
        }
        stk.push(i);
    }

    while (stk.top() != -1)
    {
        int current_height = arr[stk.top()];
        stk.pop();
        int current_width = n - stk.top() - 1;
        max_area = max(max_area, current_height * current_width);
    }
    cout << max_area;
    return 0;
}