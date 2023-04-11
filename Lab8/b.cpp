#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        a[n - 1 - i] = m % 10;
        m /= 10;
    }

    int mid = n / 2;
    int i = mid;
    int flag = 0;
    int c =  0;
    for (i = n / 2; i < n; i++)
    {

        if (a[i] == a[n - 1 - i])
        {
            continue;
        }
        else if (a[i] < a[n - 1 - i])
        {
            a[i] = a[n - 1 - i];
            c++;
        }
        else
        {
            if (a[mid] != 9 && flag == 0)
            {
                a[mid]++;
                if (n % 2 == 0)
                {
                    a[n - 1 - mid]++;
                }
                a[i] = a[n - 1 - i];
                flag++;
                c++;
            }
            else if (a[mid] == 9 && flag == 0)
            {
                a[mid] = 0;

                a[n - 1 - mid] = 0;
                int h = mid + 1;
                a[h]++;
                a[n - 1 - h]++;
                a[i] = a[n - 1 - i];
                flag++;
                c++;
            }
            else
            {
                a[i] = a[n - 1 - i];
                c++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    cout << "" << endl;
    return 0;
}