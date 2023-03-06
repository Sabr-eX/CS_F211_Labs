#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int prices[n];
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    int spreads[n];
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && prices[s.top()] <= prices[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            spreads[i] = i + 1;
        }
        else
        {
            spreads[i] = i - s.top();
        }
        s.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << spreads[i] << " ";
    }
    cout << endl;

    return 0;
}