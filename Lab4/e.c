#include <stdio.h>

long int gcd(long int a, long int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if (a == 0)
    {
        return b;
    }
    return a;
}

void LCD(long int a, long int b)
{
    long int ans = 0;
    double sqr = sqrt(a);
    for (int i = 1; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            if (gcd(a / i, b) == 1)
            {
                ans = a / i;
                break;
            }
            else if (gcd(i, b) == 1)
            {
                ans = i;
            }
        }
    }

    printf("%ld", ans);
}

int main()
{
    long int a, b;
    scanf("%ld %ld", &a, &b);
    LCD(a, b);
}