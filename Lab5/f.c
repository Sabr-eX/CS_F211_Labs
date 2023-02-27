#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int m;
    scanf("%d", &m);
    int b[n];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    if (n % 2 == 0 && m % 2 == 0)
    {
        printf("%d", 0);
    }
    else
    {
        int ans = a[0];
        for (int i = 1; i < n; i++)
        {
            ans = ans ^ a[i];
        }
        for (int i = 0; i < m; i++)
        {
            ans = ans ^ b[i];
        }

        printf("%d", ans);
    }
    return 0;
}