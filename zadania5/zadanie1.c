#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}node_t;

void print_list(node_t * head){
    node_t * current = head;
    while (current != NULL){
        printf("%d\n", current->val);
        current = current->next;
    }
}

void insert_node(node_t * head, int val){
    node_t * current = head;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = (node_t*)malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
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
    insert_node(head, 25);
    insert_node(head, 30);
    print_list(head);
    return 0;
}