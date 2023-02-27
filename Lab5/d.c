#include <stdio.h>

int maxTeams(int a[], int n, int k, int t)
{
    int lo = 0;
    int hi = 0;
    int sum = 0;
    for (int i = lo; i < k - 1; i++)
    {
        sum += a[i];
    }
    int ans = 0;
    for (hi = k - 1; hi < n; hi++)
    {
        sum += a[hi];
        if (sum / k >= t)
        {
            ans++;
            sum -= a[lo];
            lo++;
        }
        else
        {
            sum -= a[lo];
            lo++;
        }
    }
    return ans;
}

int main()
{
    int n, k, t;
    scanf("%d %d %d", &n, &k, &t);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d", maxTeams(a, n, k, t));
}