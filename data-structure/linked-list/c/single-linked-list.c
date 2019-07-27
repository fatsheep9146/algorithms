#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int key;
    struct _Node *next;
} Node;

typedef struct _List
{
    Node *head;
    int len;
} SingleLinkedList;

SingleLinkedList *newSingleLinkedList()
{
    SingleLinkedList *l = NULL;
    l = (SingleLinkedList *)malloc(sizeof(SingleLinkedList));
    if (l == NULL)
    {
        return NULL;
    }
    l->head = NULL;
    l->len = 0;
    return l;
}

void singleLinkedListFree(SingleLinkedList *obj)
{
    if (obj == NULL)
    {
        return;
    }

    Node *c = obj->head;
    Node *del = NULL;
    while (c != NULL)
    {
        del = c;
        c = c->next;
        free(del);
    }
    free(obj);
}

int singleLinkedListGet(SingleLinkedList *obj, int index)
{
    if (index < 0)
        return -1;

    if (obj == NULL || obj->head == NULL)
        return -1;

    if (index >= obj->len)
        return -1;

    int count = 0;
    Node *c = NULL;
    c = obj->head;
    while (c != NULL && count != index)
    {
        count++;
        c = c->next;
    }
    return c->key;
}

// Insert function add a new node value before the index-th node in the linked list.
void singleLinkedListAddAtIndex(SingleLinkedList *obj, int index, int val)
{
    Node *c, *p, *n;
    int count = 0;
    c = p = n = NULL;

    if (obj == NULL)
        return;

    if (index < 0 || index > obj->len)
        return;

    n = (Node *)malloc(sizeof(Node));
    if (n == NULL)
        return;
    n->key = val;
    n->next = NULL;

    c = obj->head;
    while (c != NULL && count != index)
    {
        p = c;
        count++;
        c = c->next;
    }
    obj->len++;
    if (p == NULL)
    {
        // two case: empty list or insert to head
        n->next = obj->head;
        obj->head = n;
    }
    else
    {
        n->next = p->next;
        p->next = n;
    }
}

// Delete the index-th node in the linked list
void singleLinkedListDeleteAtIndex(SingleLinkedList *obj, int index)
{
    Node *c, *p;
    int count = 0;

    c = p = NULL;

    // In case the linked list is empty
    if (obj == NULL || obj->head == NULL)
        return;

    if (index < 0 || index >= obj->len)
        return;

    c = obj->head;
    while (c != NULL && count != index)
    {
        p = c;
        count++;
        c = c->next;
    }
    if (p == NULL)
    {
        // one case: delete head
        obj->head = c->next;
        free(c);
    }
    else
    {
        p->next = c->next;
        free(c);
    }
    obj->len--;
}

void display(SingleLinkedList *obj)
{
    Node *c = NULL;
    c = obj->head;
    while (c != NULL)
    {
        printf("%d ", c->key);
        c = c->next;
    }
    printf("\n");
}

int main()
{
    SingleLinkedList *l = NULL;
    l = newSingleLinkedList();
    singleLinkedListAddAtIndex(l, 0, 1);
    singleLinkedListAddAtIndex(l, l->len, 3);
    singleLinkedListAddAtIndex(l, 1, 2);
    display(l);
    int key = singleLinkedListGet(l, 1);
    printf("%d\n", key);
    singleLinkedListDeleteAtIndex(l, 1);
    key = singleLinkedListGet(l, 1);
    printf("%d\n", key);
    display(l);
}
