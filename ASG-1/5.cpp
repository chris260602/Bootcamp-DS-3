#include<stdio.h>
#include<stdlib.h>

struct node {
    int nilai;
    node* next;
}*head = NULL, * tail = NULL;

node* createnode(int value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->nilai = value;
    temp->next = NULL;
    return temp;
}

void pushhead(int value) {
    node* temp = createnode(value);
    if (!head) {
        head = tail = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

void pushtail(int value) {
    node* temp = createnode(value);
    if (!tail) {
        head = tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}


void pushmid(int value) {
    node* temp = createnode(value);
    if (!head) {
        head = tail = temp;
    }
    else if (head->nilai < value) {
        pushhead(value);
    }
    else if (tail->nilai >= value) {
        pushtail(value);
    }
    else {
        node* curr = head;
        while (curr->next && curr->next->nilai > value) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

void printall() {
    if (!head) {
        return;
    }
    node* temp = head;
    while (temp) {
        if (!temp->next) {
            printf("%d\n", temp->nilai);
        }
        else {
            printf("%d -> ", temp->nilai);
        }
        temp = temp->next;
    }
}

void pophead() {
    if (!head) {
        return;
    }
    else if (head == tail) {
        head = tail = NULL;
    }
    else {
        node* temp = head->next;
        head->next = NULL;
        free(head);
        head = temp;
    }

}

void poptail() {
    if (!head) {
        return;
    }
    else if (head == tail) {
        head = tail = NULL;
    }
    else {
        node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        free(tail);
        tail = temp;
    }
}

void findindex(int index) {
    node* temp = head;
    int panjang = 1;
    while (temp->next) {
        temp = temp->next;
        panjang++;
    }
    panjang -= index;
    if (panjang < 0) {
        return;
    }
    node* temp2 = head;
    while (panjang != 0) {
        temp2 = temp2->next;
        panjang--;
    }
    printf("%d\n", temp2->nilai);
}

int main() {
    int index;
    pushmid(10);
    pushmid(20);
    pushmid(30);
    pushmid(40);
    pushmid(50);
    pushmid(60);
    printall();
    scanf("%d", &index);
    printf("Index dari %d: ", index);
    findindex(index);

    return 0;
}