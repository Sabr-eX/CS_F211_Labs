#include <stdio.h>

int main()
{
    long long n;
    long long d;
    scanf("%lld %lld", &n, &d);
    long long a[n];

    for (long long i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    long long lo = 0;
    long long hi = n - 1;
    long long mid = 0;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (a[mid] == d)
        {
            printf("%lld", a[mid]);
            break;
        }
        else if (lo == hi)
        {
            printf("%lld", a[lo]);
            break;
        }
        else if (a[mid] > d)
        {
            hi = mid - 1;
        }
        else if (a[mid] < d)
        {
            if (a[mid + 1] <= d)
            {
                lo = mid + 1;
            }
            else
            {
                printf("%d", a[mid]);
            }
        }
    }
    return 0;
}