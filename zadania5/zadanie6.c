#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
} node_t;

void add_node(node_t * head, int val){
    node_t * current = head;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = (node_t*)malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

void print_list(node_t * head){
    node_t * current = head;
    while (current != NULL){
        printf("%d\n", current->val);
        current = current->next;
    }
}

void insert_in_index(node_t **head, int val, int index){
    node_t * new_node = (node_t*)malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = NULL;

    if (index == 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    node_t *current = *head;
    for (int i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Index out of bounds\n");
        free(new_node);
        return;
    }

    new_node->next = current->next;
    current->next = new_node;
}

int main(){
    int value = 5;
    node_t * head = NULL;
    head = (node_t *)malloc(sizeof(node_t));
    if (head == NULL){
        return 1;
    }
    head->val = value;
    head->next = (node_t*)malloc(sizeof(node_t));
    head->next->val = 10;
    head->next->next = (node_t*)malloc(sizeof(node_t));
    head->next->next->val = 15;
    head->next->next->next = (node_t*)malloc(sizeof(node_t));
    head->next->next->next->val = 20;
    head->next->next->next->next = NULL;
    add_node(head, 25);
    add_node(head, 30);
    print_list(head);
    printf("Inserting element with value 12 at index 2:\n");
    insert_in_index(&head, 12, 2);
    print_list(head);
    return 0;
}
