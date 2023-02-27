#include <stdio.h>
#include <string.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int a[n];
    int f[k];
    memset(f, 0, sizeof(f));
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        sum += x;
        a[i] = sum;
        f[a[i] % k]++;
    }
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        if (f[i] > 2)
        {
            ans += (f[i] * (f[i] - 1)) / 2;
        }
        else if (f[i] == 2)
        {
            ans += 1;
        }
        // else if (f[i] == 1)
        // {
        //     ans += 1;
        // }
    }
    printf("%d", ans);
    return 0;
}