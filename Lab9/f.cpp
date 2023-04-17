#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;

    sort(arr, arr + n);

    if (n % 2 == 0)
    {
        int a = 0;
        int b = n / 2;

        while (a < n / 2 && b < n)
        {
            if (arr[b] - arr[a] >= k)
            {
                ans++;
                b++;
                a++;
            }
            else
            {
                b++;
            }
        }
    }
    else
    {
        int a = 0;
        int b = n / 2 + 1;

        while (a < n / 2 && b < n)
        {
            if (arr[b] - arr[a] >= k)
            {
                ans++;
                a++;
                b++;
            }
            else
            {
                b++;
            }
        }
    }

    cout << ans << endl;
}