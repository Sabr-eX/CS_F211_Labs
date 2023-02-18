#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

FILE *fp;

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

void addInBetween(song *head, int value, song *temp)
{
    song *newNode = createNode(value);
    song *var = head;
    while (var != temp->next)
    {
        var = var->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = var;
    var->prev = newNode;
}

bool exists(song *head, int search)
{
    song *temp = head;
    while (temp != NULL)
    {
        if (temp->data == search)
            return true;
        temp = temp->next;
    }
    return false;
}

void rearrangeList(song *head, int data, song *temp)
{
    song *var = head;

    while (var->next != NULL)
    {
        if (var->data == data)
            break;
        var = var->next;
    }
    if (var->next != NULL && var->prev != NULL)
    {
        var->prev->next = var->next;
        var->next->prev = var->prev;
        temp->next->prev = var;
        var->next = temp->next;
        temp->next = var;
        var->prev = temp;
    }
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
    fp = fopen("test2.txt", "r");
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
        else if (operation == 6)
        {
            int x;
            fscanf(fp, "%d", &x);
            if (exists(head, x))
            {
                rearrangeList(head, x, temp);
            }
            else
            {
                addInBetween(head, x, temp);
            }
        }
        else
        {
            break;
        }
    }
    free(fp);
    free(head);
}