#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node
{
    long long data;
    struct Node *next;
    struct Node *prev;
} Node;

// Creates a new node with given value and returns a pointer to it
Node *createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
// Creates a new node with given value and adds it to
// the back of the given singly linked list,
// returns a pointer to the newly created node
Node *addToList(Node *head, int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
    {
        return newNode;
    }
    Node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
    newNode->prev = cur;
    return newNode;
}
// Creates a singly linked list by reading input and
// returns a pointer the head of the newly created linked list
Node *readList()
{
    int n;
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
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
// Prints the values stored in the nodes of the given singly linked list
void printList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%lld ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}
// Frees the memory dynamically allocated to
// all the nodes of the given singly linked list
void freeList(Node *head)
{
    Node *cur, *nxt;
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
    Node *head = readList();
    Node *first = head;
    Node *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    long long sum1 = first->data;
    long long sum2 = last->data;
    long long no1 = 1;
    long long no2 = 1;
    long long ans1 = 0;
    long long ans2 = 0;

    while (first != last)
    {
        if (sum1 == sum2)
        {
            ans1 = no1;
            ans2 = no2;
            if (first->next != last)
            {
                first = first->next;
                no1++;
                last = last->prev;
                no2++;
            }
        }
        else if (sum1 < sum2)
        {
            first = first->next;
            sum1 += first->data;
            no1++;
        }
        else if (sum2 < sum1)
        {
            last = last->prev;
            sum2 += last->data;
            no2++;
        }
    }
    printf("%lld %lld", ans1, ans2);
    freeList(head);
    return 0;
}