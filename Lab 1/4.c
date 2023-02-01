#include <stdio.h>

int main()
{
    printf("Enter the lenght of the array:\n");
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int las;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > 0)
        {
            continue;
        }
        else
        {
            las = i + 1;

            break;
        }
    }
    printf("%d\n", las);

    for (int i = las - 1; i >= 0; i--)
    {
        if (a[i] > 0)
        {
            for (int j = i; j < las - 1; j++)
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            las -= 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }

    return 0;
}