#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct Node {
    struct Node* before;
    int data[3];
    struct Node* next;
};
//
//void addNode(struct Node* target, struct Node* tail, int data[]) {
//    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//    if (tail->before == NULL) {
//        newNode->next = tail;
//        newNode->before = target;
//        tail->before = newNode;
//        target->next = newNode;
//        for (int i = 0; i < 3; i++)
//            newNode->data[i] = data[i];
//    }
//    else
//    {
//        struct Node* tempNode = target->next;
//        tempNode->before = newNode;
//        newNode->next = target->next;
//        target->next = newNode;
//        for (int i = 0; i < 3; i++)
//            newNode->data[i] = data[i];
//    }
// 안녕하세요 ㅎㅎㅎㅎㅎㅎ
//}
void printNode(struct Node* target) {
    int count = 0;
    struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
    curr = target->next;
    while (curr->next!=NULL) {

        printf("%d : ", count + 1);
        for (int i = 0; i < 3; i++) {
            printf("%d ", curr->data[i]);
        }
        curr = curr->next;
        count++;
        printf("\n");
    }
}

void main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->next = NULL;
    head->before = NULL;
    struct Node* tail = (struct Node*)malloc(sizeof(struct Node));
    tail->next = NULL;
    tail->before = NULL;

    int score[3] = { 80, 90, 100 };
    int score2[3] = { 71, 30, 300 };
    addNode(head, tail, score);
    addNode(head, tail, score2);
    printNode(head);
}