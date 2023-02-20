#include <stdio.h>
#include <stdlib.h>

typedef struct candi
{
    int num;
    int votes;
} candi;

void merge(candi *a[], int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    candi *LeftArray[n1];
    candi *RightArray[n2]; // temporary arrays

    /* copy data to temp arrays */
    for (int i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i];
    for (int j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];

    i = 0;   /* initial index of first sub-array */
    j = 0;   /* initial index of second sub-array */
    k = beg; /* initial index of merged sub-array */

    while (i < n1 && j < n2)
    {
        if (LeftArray[i]->votes <= RightArray[j]->votes)
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

void mergeSort(candi *a[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    candi *c[n];
    for (int i = 0; i < n; i++)
    {
        c[i] = (candi *)malloc(sizeof(candi));
        c[i]->num = i + 1;
        c[i]->votes = 0;
    }
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        c[a[i] - 1]->votes++;
    }
    mergeSort(c, 0, n - 1);

    for (int i = n - 1; i >= n - k; i--)
    {
        printf("%d ", c[i]->num);
    }
}