#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string str;
    cin >> str;
    stack<char> st;
    int b = 0;
    int a = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            st.push('(');
            a++;
        }
        else if (a == 0 && str[i] == ')')
        {
            b++;
        }
        else if (str[i] == ')')
        {
            st.push(')');
            a--;
        }
    }
    cout << a + b << endl;
    return 0;
}