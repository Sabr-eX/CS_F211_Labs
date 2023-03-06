#include <iostream>
using namespace std;

class MinStack
{
    int min = INT32_MAX;
    int a[1000];
    int minTop = 0;
    int b[1000] = {INT32_MAX};
    int top = 0;

public:
    void push(int val)
    {
        a[++top] = val;
        if (b[minTop] < val)
        {
            b[++minTop] = b[minTop - 1];
        }
        else
        {
            b[++minTop] = val;
        }
    }

    void pop()
    {
        top--;
        minTop--;
    }

    void printTop()
    {
        cout << "Top Element: " << a[top] << endl;
    }

    void printMin()
    {
        cout << "Smallest Element: " << b[minTop] << endl;
    }
};

int main()
{
    MinStack ms;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ms.push(x);
    }

    int m;
    cin >> m;

    while (m--)
    {
        int o;
        cin >> o;
        switch (o)
        {
        case 1:
            int v;
            cin >> v;
            ms.push(v);
            break;
        case 2:
            ms.pop();
            break;
        case 3:
            ms.printTop();
            break;
        case 4:
            ms.printMin();
            break;
        default:
            cout << "Enter a valid command" << endl;
        }
    }
    return 0;
}