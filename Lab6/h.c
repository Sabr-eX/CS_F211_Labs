// Divya's Logic

#include <stdio.h>
#include <stdlib.h>
typedef struct node_t
{
    struct node_t *prev;
    struct node_t *next;
    int data;
} Node;

Node *createNode(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node *enqueue(Node *front, Node *rear, int data)
{
    Node *newNode = createNode(data);

    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;

        rear->next = front;
        front->prev = rear;
    }

    return rear;
}

Node *dequeue(Node *front, Node *rear, int data)
{
    if (front == NULL)
    {
        return front;
    }
    else
    {
        Node *temp = front;
        front = front->next;
        free(temp);

        front->prev = rear;
        rear->next = front;
    }

    return front;
}

Node *iterate(Node *front, Node *rear, int k)
{
    Node *temp = front;

    while (rear != front)
    {
        for (int i = 0; i < k - 1; i++)
        {
            temp = temp->next;
        }

        Node *del = temp;

        if (del == front)
        {
            front = front->next;
        }
        else if (del == rear)
        {
            rear = rear->prev;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        temp = temp->next;
        free(del);
    }

    return front;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    Node *front = NULL;
    Node *rear = NULL;

    for (int i = 1; i <= n; i++)
    {
        if (front == NULL)
        {
            front = enqueue(front, rear, i);
            rear = front;
        }
        else
        {
            rear = enqueue(front, rear, i);
        }
    }

    front = iterate(front, rear, k);
    printf("%d", front->data);
    return 0;
}