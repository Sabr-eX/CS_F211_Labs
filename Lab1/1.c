#include <stdio.h>

int main()
{
    printf("Enter m n\n");
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    long long sum = 0;

    int b[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int c;
            scanf("%d", &c);
            sum += c;
            b[i][j] = sum;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", b[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    printf("Enter ri, ci, rh, ch\n");
    int ri, ci, rh, ch;
    scanf("%d %d %d %d", &ri, &ci, &rh, &ch);
    if (m - ri >= rh && n - ci >= ch)
    {
        int c[rh][ch];
        for (int i = ri; i < ri + rh; i++)
        {
            for (int j = ci; j < ci + ch; j++)
            {
                c[i - ri][j - ci] = b[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < rh; i++)
        {
            for (int j = 0; j < ch; j++)
            {
                ans += c[i][j];
                printf("%d", c[i][j]);
                printf(" ");
            }
            printf("\n");
        }
        printf("%d", ans);
    }
    else
    {
        printf("Not possible");
    }

    return 0;
}