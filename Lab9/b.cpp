#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    int preSum[n];
    int leftcand[n];
    int rightcand[n];

    if (s[0] == '*')
        preSum[0] = 1;
    else
        preSum[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int a = 0;

        if (s[i] == '*')
            a = 1;

        preSum[i] = preSum[i - 1] + a;
    }

    if (s[0] == '|')
        leftcand[0] = 0;
    else
        leftcand[0] = -1;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == '|')
            leftcand[i] = i;
        else
            leftcand[i] = leftcand[i - 1];
    }

    if (s[n - 1] == '|')
        rightcand[n - 1] = n - 1;
    else
        rightcand[n - 1] = n;

    for (int i = n - 2; i >= 0; --i)
    {
        if (s[i] == '|')
            rightcand[i] = i;
        else
            rightcand[i] = rightcand[i + 1];
    }

    while (q--)
    {
        int s, e;
        cin >> s >> e;

        int left = rightcand[s];
        int right = leftcand[e];

        if (left < right)
        {
            int ans = preSum[right] - preSum[left];
            cout << ans << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}