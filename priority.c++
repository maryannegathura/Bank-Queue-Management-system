// Priority Queue: bank customers, highest priority served first
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char name[50];
    int priority;
    struct node *next;
};

struct node *head = NULL;

struct node* newNode(const char *name, int priority) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->name, name);
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void insert(struct node *newNode) {
    // Case 1: list is empty, or the new customer outranks the head
    if (head == NULL || newNode->priority > head->priority) {
        newNode->next = head;
        head = newNode;
        return;
    } 

    // Case 2: walk forward to find the spot
        struct node *current = head;
        while (current->next != NULL && current->next->priority >= newNode->priority) {
            current = current->next;
        }

        //Link the new node in after current
        newNode->next = current->next;
        current->next = newNode;
    }

void display() {
    struct node *current = head;
    while (current != NULL) {
        printf("%s %d\n", current->name, current->priority);
        current = current->next;
    }
}

void dequeue() {
if (head == NULL) {
        printf("The queue is empty.\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}

int main() {
    printf("Priority queue starting\n");

    insert(newNode("Alice", 1));
    insert(newNode("Bob", 3));
    insert(newNode("Charlie", 2));
    insert(newNode("Diana", 3));


    display();

    dequeue(); 
    display();
    return 0;
}