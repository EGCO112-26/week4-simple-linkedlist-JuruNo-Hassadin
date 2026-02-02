#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

typedef struct node* NodePtr;

/* insert node at end */
void insert(NodePtr *head, int id, char *name) {
    NodePtr newNode = (NodePtr)malloc(sizeof(struct node));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    NodePtr temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/* print all nodes */
void printList(NodePtr head) {
    while (head != NULL) {
        printf("%d %s\n", head->id, head->name);
        head = head->next;
    }
}

/* free all nodes */
void freeList(NodePtr head) {
    NodePtr temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(int argc, char *argv[]) {
    NodePtr head = NULL;

    /* insert from command-line arguments */
    for (int i = 1; i < argc; i += 2) {
        int id = atoi(argv[i]);
        char *name = argv[i + 1];
        insert(&head, id, name);
    }

    printList(head);
    freeList(head);

    return 0;
}
