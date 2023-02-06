#include <stdio.h>

typedef struct Medal
{
    char name[20];
    int gold;
    int silver;
    int bronze;
} medal;

int main()
{
    int n;
    scanf("%d", &n);
    medal country[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", &country[i].name, &country[i].gold, &country[i].silver, &country[i].bronze);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (country[i].gold < country[j].gold)
            {
                medal temp = country[i];
                country[i] = country[j];
                country[j] = temp;
            }
            else if (country[i].gold == country[j].gold)
            {
                if (country[i].silver < country[j].silver)
                {
                    medal temp = country[i];
                    country[i] = country[j];
                    country[j] = temp;
                }
                else if (country[i].silver == country[j].silver)
                {
                    if (country[i].bronze < country[j].bronze)
                    {
                        medal temp = country[i];
                        country[i] = country[j];
                        country[j] = temp;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", country[i].name);
    }
    return 0;
}