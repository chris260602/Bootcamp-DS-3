#include<stdio.h>
#include<stdlib.h>


struct node {
    int value;
    node* next;
}*head, * tail;

node* createnode(int value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

void push(int value) {
    node* temp = createnode(value);
    if (!head) {
        head = tail = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

int max(node* curr) {
    int max = 0;
    node* temp = curr;
    while (temp) {
        max = temp->value > max ? temp->value : max;
        temp = temp->next;
    }
    return max;
}

int min(node* curr) {
    int min = curr->value;
    node* temp = curr;
    while (temp) {
        min = temp->value < min ? temp->value : min;
        temp = temp->next;
    }
    return min;
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    int Minvalue = min(head);
    int Maxvalue = max(head);
    printf("The range is %d\n", Maxvalue - Minvalue);


    return 0;
}