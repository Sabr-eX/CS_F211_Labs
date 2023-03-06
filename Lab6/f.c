#include <stdio.h>
#include <stdlib.h>

typedef struct lexi
{
    int data;
    struct lexi *next;
    struct lexi *prev;
} lexi;

lexi *push_back(lexi *end, int val)
{
    lexi *newLexi = malloc(sizeof(lexi));
    newLexi->data = val;
    newLexi->prev = end;
    end->next = newLexi;
    newLexi->next = NULL;
    end = newLexi;
    return end;
}

lexi *push_front(lexi *front, int val)
{
    lexi *newLexi = malloc(sizeof(lexi));
    newLexi->data = val;
    newLexi->next = front;
    newLexi->prev = NULL;
    front->prev = newLexi;
    front = newLexi;
    return front;
}

void printList(lexi *front)
{
    lexi *cur = front;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    lexi *front;
    lexi *back;
    front = back = push_front(front, a[0]);

    for (int i = 1; i < n; i++)
    {
        if (a[i] <= front->data)
        {
            front = push_front(front, a[i]);
        }
        else
        {
            back = push_back(back, a[i]);
        }
    }

    printList(front);
    return 0;
}