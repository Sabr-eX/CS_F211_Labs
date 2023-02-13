#include <stdio.h>

int main()
{
    int n;
    int k;
    scanf("%d %d", &n, &k);

    int a[n];
    int max = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    int lo = 0;
    int hi = max;
    int mid;
    int ans = 0;

    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (mid == 0)
        {
            break;
        }
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            num += a[i] / mid;
        }

        if (num >= k)
        {
            lo = mid + 1;
            ans = mid;
        }
        else if (num < k)
        {
            hi = mid - 1;
        }
    }
    printf("%d", ans);
    return 0;
}