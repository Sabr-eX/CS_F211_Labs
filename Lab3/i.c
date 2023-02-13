#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{

    int n;
    scanf("%d", &n);

    int low = 1;
    int high = n;
    int mid;
    int ans = 0;
    int count = (n * (n - 1)) / 2;
    while (low <= high)
    {
        mid = (low + high) / 2;
        int count2 = (n - mid) * (n - mid + 1) / 2;
        if (count - count2 < count / 2)
        {

            low = mid + 1;
            ans = mid;
        }
        else if (count - count2 > count / 2)
        {

            high = mid - 1;
        }
        else
        {
            ans = mid;
            break;
        }
    }

    printf("%d", ans);
}