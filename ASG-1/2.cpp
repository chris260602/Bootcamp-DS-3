#include<stdio.h>
#include<stdlib.h>


struct node {
    int value;
    node* next;
}*head, * tail;

node* createnode(int value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    temp->value = value;
    return temp;
}

void push(int value) {
    node* temp = createnode(value);
    if (!head) {
        head = temp;
    }
    else {
        node* curr = head;
        while (curr->next && curr->next != head) {
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = head;
    }
}

void print() {
    node* temp = head;
    do {
        if (temp->next == head) {
            printf("%d\n", temp->value);
        }
        else {
            printf("%d -> ", temp->value);
        }
        temp = temp->next;
    } while (temp && temp != head);
}

bool circular(node* target) {
    if (!head) {
        return false;
    }
    node* temp1 = head;
    node* temp2 = head;
    while (temp1 && temp2 && temp1->next && temp2->next->next) {
        temp1 = temp1->next;
        temp2 = temp2->next->next;
        if (temp1 == temp2) {
            return true;
        }
    }
    return false;
}


int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    print();
    if (circular(head) == true) {
        puts("Circular");
    }
    else {
        puts("Not Circular");
    }
    return 0;
}