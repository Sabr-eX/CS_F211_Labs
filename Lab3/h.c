#include <stdio.h>

int main()
{
    long long n;
    scanf("%lld", &n);

    long long lo = 1;
    long long hi = n;
    long long mid = 0;

    while (lo <= hi)
    {
        mid = (lo + hi) / 2;

        if (mid > 1e9)
        {
            hi = mid - 1;
            continue;
        }

        if (mid * mid < n)
        {
            if ((mid + 1) * (mid + 1) <= n)
            {
                lo = mid + 1;
            }
            else
            {
                printf("%lld", mid);
                break;
            }
        }
        else if (mid * mid > n)
        {
            hi = mid - 1;
        }
        else
        {
            printf("%lld", mid);
            break;
        }
    }

    return 0;
}