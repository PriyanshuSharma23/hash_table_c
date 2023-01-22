struct Node
{
    int val;
    struct Node *next;
};

struct Node *createNode(int val)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;

    return node;
}

void pushNode(struct Node **head, int val)
{

    struct Node *newNode = createNode(val);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *tempPtr = *head;

    while (tempPtr->val != val && tempPtr->next != NULL)
    {
        tempPtr = tempPtr->next;
    }

    if (tempPtr->val == val)
    {
        return;
    }

    tempPtr->next = newNode;
    return;
}

int popNode(struct Node **head, int val)
{
    if (*head == NULL)
    {
        return -1;
    }

    if ((*head)->val == val)
    {
        *head = NULL;
        return 0;
    }

    struct Node *tempPtr = *head;

    while (tempPtr->next->val != val && tempPtr->next != NULL)
    {
        tempPtr = tempPtr->next;
    }

    if (tempPtr->next == NULL)
    {
        return -1;
    }

    struct Node *nextToNext = tempPtr->next->next;
    free(tempPtr->next);

    tempPtr->next = nextToNext;
    return 0;
}

int findNode(struct Node *head, int val)
{
    if (head == NULL)
    {
        return -1;
    }

    struct Node *tempPtr = head;

    while (tempPtr->val != val && tempPtr->next != NULL)
    {
        tempPtr = tempPtr->next;
    }

    if (tempPtr->val == val)
    {
        return 0;
    }

    return -1;
}

void freeNode(struct Node *head)
{
    if (head == NULL)
    {
        return;
    }

    struct Node *tempPtr = head;

    while (tempPtr->next != NULL)
    {
        struct Node *next = tempPtr->next;
        free(tempPtr);
        tempPtr = next;
    }

    free(tempPtr);
}
