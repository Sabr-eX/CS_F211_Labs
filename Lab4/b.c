#include <stdio.h>

/* Function to merge the subarrays of a[] */
void merge(long int a[], long int beg, long int mid, long int end)
{
    long int i, j, k;
    long int n1 = mid - beg + 1;
    long int n2 = end - mid;

    long int LeftArray[n1], RightArray[n2]; // temporary arrays

    /* copy data to temp arrays */
    for (long int i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i];
    for (long int j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];

    i = 0;   /* initial index of first sub-array */
    j = 0;   /* initial index of second sub-array */
    k = beg; /* initial index of merged sub-array */

    while (i < n1 && j < n2)
    {
        if (LeftArray[i] <= RightArray[j])
        {
            a[k] = LeftArray[i];
            i++;
        }
        else
        {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = LeftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = RightArray[j];
        j++;
        k++;
    }
}

void mergeSort(long int a[], long int beg, long int end)
{
    if (beg < end)
    {
        long int mid = (beg + end) / 2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}

/* Function to print the array */
void printArray(long int a[], long int n)
{
    long int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    long int n;
    scanf("%ld", &n);
    long int a[n];
    for (long int i = 0; i < n; i++)
    {
        scanf("%ld", &a[i]);
    }
    printf("Before sorting array elements are - \n");
    printArray(a, n);
    mergeSort(a, 0, n - 1);
    printf("After sorting array elements are - \n");
    printArray(a, n);
    for (long int i = 0; i < n; i++)
    {
        if (a[i] >= n - i)
        {
            printf("%ld", n - i);
            break;
        }
        else
        {
            continue;
        }
    }
    return 0;
}