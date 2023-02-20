#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void Sieve(int n, bool prime[], long int no[])
{

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;

            for (int i = 2; i <= n; i++)
            {
                no[i] = no[i - 1] + prime[i];
            }
        }
    }
}

int main()
{
    long int n;
    long int q;
    scanf("%ld %ld", &n, &q);

    long int prime[n + 1];
    long int no[n + 1];
    memset(no, 0, sizeof(no));
    memset(prime, true, sizeof(prime));

    Sieve(n, prime, no);
    while (q--)
    {
        long int x;
        scanf("%ld", &x);

        printf("%ld ", no[x]);
    }

    return 0;
}