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
    long long k;
    scanf("%lld", &k);
    Node *head = readList();
    // printList(head);
    Node *first = head;
    Node *last;
    Node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    last = cur;
    while (first != last)
    {
        if (first->data + last->data == k)
        {

            printf("1");
            return 0;
        }
        else if (first->data + last->data < k)
        {
            if (first->next == last)
            {
                printf("0");
                return 0;
            }
            first = first->next;
        }
        else if (first->data + last->data > k)
        {
            if (first->next == last)
            {
                printf("0");
                return 0;
            }
            last = last->prev;
        }
    }
    freeList(head);
    return 0;
}