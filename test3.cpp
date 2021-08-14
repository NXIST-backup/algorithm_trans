#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index)
{
    if (head == NULL) {
        if (index != 0) {
            return printf("failed\n");
        }
    }
    if (index == 0) {
        node->next = head;
        head = node;
        return printf("success\n");
    }
    Node *current_node = head;
    int count = 0;
    while (current_node != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if (count == index - 1) {
        node->next = current_node->next;
        current_node->next = node;
    }
    return printf("success\n");
}

void output(LinkedList head)
{
    if (head == NULL) {
        return;
    }
    Node *current_node = head;
    while (current_node != NULL) {
        printf("%d", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

void clear(LinkedList head)
{
    Node *current_node = head;
    while (current_node != NULL) {
        Node *delete_node = current_node;
        current_node = current_node->next;
        free(delete_node);
    }
}

int main()
{
    LinkedList linkedlist = NULL;
    int n;
    scanf("%d", &n);
    int p, q;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &p, &q);
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = q;
        node->next = NULL;
        linkedlist = insert(linkedlist, node, p);
    }
    output(linkedlist);
    clear(linkedlist);
    return 0;
}