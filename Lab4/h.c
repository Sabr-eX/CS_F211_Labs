#include <stdio.h>

void findMax(int n, int m)
{
    long int max = ((n - m) * (n - m + 1)) / 2;
    printf("%d", max);
}

void findMin(int n, int m)
{
    int div = n / m;
    int rem = n % m;
    int min = (((div + 1) * (div)) / 2) * rem + (((div) * (div - 1)) / 2) * (m - rem);
    printf("%d ", min);
}

int main()
{
    int n;
    int m;
    scanf("%d %d", &n, &m);
    findMin(n, m);
    findMax(n, m);

    return 0;
}