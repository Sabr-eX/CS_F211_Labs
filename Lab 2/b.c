#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct Node_t
{
    int data;
    struct Node_t *next;
};
typedef struct Node_t Node;
// Creates a new node with given dataue and returns a pointer to it
Node *createNode(int dataue)
{
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = dataue;
    newNode->next = NULL;
    return newNode;
}
// Creates a new node with given dataue and adds it to
// the back of the given singly linked list,
// returns a pointer to the newly created node
Node *addToList(Node *head, int data)
{
    Node *newNode = createNode(data);
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
// Prints the dataues stored in the nodes of the given singly linked list
void printList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
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

Node *mergeLists(Node *head1, Node *head2)
{

    Node *node1 = head1;
    Node *node2 = head2;
    Node *ans = NULL;
    Node *node = NULL;

    if (node1 == NULL && node2 == NULL)
    {
        return NULL;
    }
    else if (node1 == NULL)
    {
        return node2;
    }
    else if (node2 == NULL)
    {
        return node1;
    }
    else
    {

        if (node1->data < node2->data)
        {
            ans = head1;
            node = head1;
            node1 = node1->next;
        }
        else
        {
            ans = head2;
            node = head2;
            node2 = node2->next;
        }

        while (node1 != NULL && node2 != NULL)
        {
            if (node1->data < node2->data)
            {
                node->next = node1;
                node = node1;
                node1 = node->next;
            }
            else
            {
                node->next = node2;
                node = node2;
                node2 = node->next;
            }
        }
        if (node1 == NULL && node2 != NULL)
        {
            while (node2 != NULL)
            {
                node->next = node2;
                node = node2;
                node2 = node->next;
            }
            node->next = NULL;
        }
        else if (node1 != NULL && node2 == NULL)
        {
            while (node1 != NULL)
            {
                node->next = node1;
                node = node1;
                node1 = node->next;
            }
            node->next = NULL;
        }
        else
        {
            node->next = NULL;
        }
        return ans;
    }
}

int main()
{
    Node *head1 = readList();
    Node *head2 = readList();
    Node *merged = mergeLists(head1, head2);
    printList(merged);
    freeList(merged);
}
