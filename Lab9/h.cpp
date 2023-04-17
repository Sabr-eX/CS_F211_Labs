#include <bits/stdc++.h>
using namespace std;

bool allocationPossible(int mid, int student, int book, int page[])
{
    int allocatedStudents = 1;
    int pages = 0;

    for (int i = 0; i < book; i++)
    {
        if (page[i] > mid)
            return false;

        if (page[i] + pages > mid)
        {
            allocatedStudents++;
            pages = page[i];
        }
        else
        {
            pages += page[i];
        }
    }

    if (allocatedStudents > student)
        return false;
    else
        return true;
}

int main()
{
    int book, student;
    cin >> book >> student;

    int pages[book];
    int totalPage = 0;

    for (int i = 0; i < book; i++)
    {
        cin >> pages[i];
        totalPage += pages[i];
    }

    int low = 0;
    int high = totalPage;
    int mid;
    int res = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (allocationPossible(mid, student, book, pages))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << res;

    return 0;
}