#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int a = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        a = a ^ arr[i];
    }

    int k;
    scanf("%d", &k);
    int brr[k];
    int b = 0;

    for (int i = 0; i < k; i++)
    {
        scanf("%d", &brr[i]);
        b = b ^ brr[i];
    }

    int ans = 0;

    if (n % 2 == 0)
    {
        b = 0;
    }

    if (k % 2 == 0)
    {
        a = 0;
    }

    ans = a ^ b;
    printf("%d", ans);
}