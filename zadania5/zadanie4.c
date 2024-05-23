#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}node_t;

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

void remove_by_index(node_t **head, int index){
    if (*head == NULL) {
        return;
    }

    node_t *current = *head;
    if (index == 0) {
        *head = current->next;
        free(current);
        return;
    }

    for (int i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        return;
    }

    node_t *next = current->next->next;
    free(current->next);
    current->next = next;
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
    printf("Removing element at index 2:\n");
    remove_by_index(&head, 2);
    print_list(head);
    return 0;
}
