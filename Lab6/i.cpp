#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string input;
    string stir;
    stack<string> stk;
    cin >> input;
    int n = input.length();
    int i = 0;
    while (i != n)
    {
        char x;
        x = input[i];
        if (x == '/')
        {
            if (stir == "..")
            {
                stk.pop();
                stir.clear();
            }
            else if (stir == ".")
            {
                stir.clear();
            }
            else if (stir.length() != 0)
            {
                stk.push(stir);
                stir.clear();
            }
        }
        else
        {
            stir = stir + x;
        }
        i++;
    }

    if (stir.length() != 0)
    {
        stk.push(stir);
        stir.clear();
    }

    while (!stk.empty())
    {
        string temp = stk.top();
        stk.pop();
        stir = temp + '/' + stir;
    }

    stir = '/' + stir;
    stir.erase(stir.end() - 1);

    cout << stir << endl;

    return 0;
}