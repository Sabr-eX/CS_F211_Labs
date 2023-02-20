#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int left[n];
    int right[n];

    left[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        left[i] = gcd(left[i - 1], arr[i]);
    }

    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = gcd(right[i + 1], arr[i]);
    }

    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        int exc;

        if (i == 0)
            exc = right[1];
        else if (i == n - 1)
            exc = left[n - 2];
        else
            exc = gcd(left[i - 1], right[i + 1]);

        if (exc > ans)
            ans = exc;
    }
    printf("%d", ans);
}