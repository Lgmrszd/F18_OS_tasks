#include <stdio.h>
#include <stdlib.h>


typedef struct LinkedNode {
    int data;
    struct LinkedNode* next;
} LinkedNode;

typedef struct {
    struct LinkedNode* head;
} LinkedList;

void print_list(LinkedList* list){
    LinkedNode* node = list->head;
    if (node == NULL) return;
    printf("%d", node->data);
    while (node->next != NULL) {
        node = node->next;
        printf(" %d", node->data);
    }
    printf("\n");
}

LinkedNode *create_node(int data){
    LinkedNode *node = (LinkedNode*) malloc(sizeof(LinkedNode));
    node->data = data;
    node->next = NULL;
}

void insert_node(LinkedList *list, int index, int data){
    LinkedNode* node = list->head;
    LinkedNode* new_node = create_node(data);
    if (node == NULL) {
        list->head = new_node;
        return;
    }
    if (index < 1) {
        new_node->next = node;
        list->head = new_node;
        return;
    }
    index--;
    while (node->next != NULL && index>0) {
        node = node->next;
        index--;
    }
    new_node->next = node->next;
    node->next = new_node;
}

void delete_node(LinkedList *list, int index) {
    if (list->head == NULL) return;
    if (index < 1) {
        LinkedNode *old_node = list->head;
        list->head = old_node->next;
        free(old_node);
        return;
    }
    LinkedNode* node = list->head;
    index--;
    while (node->next != NULL && index>0) {
        node = node->next;
        index--;
    }
    LinkedNode* next_node = node->next;
    if (next_node != NULL) {
        node->next = next_node->next;
        free(next_node);
    }
}

void append_node(LinkedList *list, int data){
    LinkedNode* node = list->head;
    LinkedNode* new_node = create_node(data);
    if (node == NULL) {
        list->head = new_node;
        return;
    }
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = new_node;
}

LinkedList *create_list(){
    LinkedList *list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

int main(){
    LinkedList *list = create_list();
    append_node(list, 2);
    append_node(list, 3);
    append_node(list, 4);
    append_node(list, 6);
    print_list(list);
    insert_node(list, 3, 5);
    insert_node(list, 0, 0);
    insert_node(list, 1, 1);
    insert_node(list, 100, 1000);
    delete_node(list, 1);
    delete_node(list, 100);
    print_list(list);
    return 0;
}

