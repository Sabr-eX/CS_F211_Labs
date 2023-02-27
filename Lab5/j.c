#include <stdio.h>
#include <time.h>

int main()
{
    int n;
    scanf("%d", &n);

    long long randomnumber;
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        scanf("%d", &x);

        t = time(NULL);
        if (((t + x) % i) == 0)
        {
            randomnumber = x;
        }
        printf("%d\n", randomnumber);
    }
    return 0;
}