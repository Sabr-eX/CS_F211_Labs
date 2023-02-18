#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct hehe
{
    int data;
    struct hehe *next;
    struct hehe *prev;
} song;

song *createNode(int value)
{
    song *newNode = malloc(sizeof(song));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

song *addToList(song *head, int val)
{
    song *newNode = createNode(val);
    if (head == NULL)
    {
        return newNode;
    }
    song *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
    newNode->prev = cur;
    return newNode;
}
FILE *fp;
song *readList()
{
    int n;
    if (fp != NULL)
        fscanf(fp, "%d", &n);

    song *head = NULL;
    for (int i = 0; i < n; ++i)
    {
        int x;
        fscanf(fp, "%d", &x);
        if (head == NULL)
        {
            head = addToList(head, x);
        }
        else
        {
            addToList(head, x);
        }
    }
    return head;
}

void printList(song *head)
{
    song *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}

void freeList(song *head)
{
    song *cur, *nxt;
    cur = head;
    while (cur != NULL)
    {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }
}
int main()
{
    fp = fopen("test.txt", "r");
    song *head = readList();

    int operation;
    song *temp = head;

    while (true)
    {
        fscanf(fp, "%d", &operation);

        if (operation == 1)
        {
            int x;
            fscanf(fp, "%d", &x);
            addToList(head, x);
        }
        else if (operation == 2)
        {
            if (temp != NULL)
                printf("%d\n", temp->data);
            else
                break;
        }
        else if (operation == 3)
        {
            if (temp->next != NULL)
                temp = temp->next;
        }
        else if (operation == 4)
        {
            if (temp->prev != NULL)
                temp = temp->prev;
        }
        else
        {
            break;
        }
    }
    free(fp);
    free(head);
}