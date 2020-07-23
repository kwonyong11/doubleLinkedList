#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct Node {
    struct Node* before;
    char* name;
    int data[3];
    struct Node* next;
};

void addNode(struct Node* target, struct Node* tail,char* name, int data[]) {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   if (tail->before == NULL) {
       newNode->next = tail;
       newNode->before = target;
       tail->before = newNode;
       target->next = newNode;
       newNode->name = name;
       for (int i = 0; i < 3; i++)
           newNode->data[i] = data[i];
   }
   else
   {
       struct Node* tempNode = target->next;
       tempNode->before = newNode;
       newNode->next = target->next;
       target->next = newNode;
       newNode->name = name;
       for (int i = 0; i < 3; i++)
           newNode->data[i] = data[i];
   }
}
void printNode(struct Node* target) {
    int count = 0;
    struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
    curr = target->next;
    int result =0;
    float aver=0;
    char* sub[3] = {"����","����","����"};
    while (curr->next!=NULL) {
        printf("\n");
        printf("%d : ", count + 1);
        printf("%s\t", curr->name);
        for (int i = 0; i < 3; i++) {
            result += curr->data[i];
            printf("%s���� : %d ",sub[i], curr->data[i]);
        }
        printf("���� : %d\t",result);
        aver = ((float)result)/3;
        printf("��� : %.2f",aver);
        curr = curr->next;
        count++;
        printf("\n");
        result =0;
    }
}

void main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->next = NULL;
    head->before = NULL;
    struct Node* tail = (struct Node*)malloc(sizeof(struct Node));
    tail->next = NULL;
    tail->before = NULL;
    char* name[3];

    int score[3][3];

    printf("�л�3���� �̸��� �Է��ϼ��� : ");
    for(int i=0; i<3; i++){
        char* temp_name = (char*)malloc(sizeof(char));
        scanf("%s",temp_name);
        name[i] = temp_name;
    }
    for(int i =0; i<3; i++) {
        printf("%s�� ���� / ���� / ������ ������ �Է��ϼ���", name[i]);
        for(int j=0; j<3; j++){
            scanf("%d",&score[i][j]);
        }
    }
    for(int i=0; i<3; i++){
            addNode(head,tail,name[i],score[i]);
    }
    printNode(head);
}