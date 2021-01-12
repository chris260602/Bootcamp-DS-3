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

void pop(int value) {
    if (!head) {
        return;
    }
    else if (value == head->nilai) {
        pophead();
    }
    else if (value == tail->nilai) {
        poptail();
    }
    else {
        node* temp = head;
        while (temp->next && temp->next->nilai != value) {
            temp = temp->next;
        }
        if (!temp->next) {
            return;
        }
        node* temp2 = temp->next;
        if (temp->next->next) {
            temp->next = temp->next->next;
            temp->next->next = NULL;
        }
        else {
            temp->next = NULL;
        }
        free(temp2);
    }
}

void delet() {
    if (!head) {
        return;
    }
    node* temp = head;
    while (temp) {
        if (!temp->next) {
            return;
        }
        node* temp2 = temp->next;
        while (temp2) {
            if (temp->nilai == temp2->nilai) {
                pop(temp2->nilai);
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

void deleteall() {
    node* temp = head;
    if (!head) {
        return;
    }
    delet();
    while (temp) {
        temp = temp->next;
        delet();
    }
}

int main() {
    pushmid(10);
    pushmid(20);
    pushmid(20);
    pushmid(10);
    pushmid(10);
    pushmid(10);
    printall();
    deleteall();
    printall();



    return 0;
}