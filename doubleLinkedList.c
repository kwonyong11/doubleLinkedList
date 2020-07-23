#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct Node
{
  struct Node *before;
  char* name;
  int data[3];
  struct Node *next;
};

void addNode(struct Node *target, struct Node *tail,char* name, int *data[]);
void printNode(struct Node *target);

void addNode(struct Node *target, struct Node *tail,char* name, int *data[])
{
  struct Node *newNode;
  newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->name=name;
  for (int i = 0; i < 3; i++)
    {
      newNode->data[i] = data[i];
    }
  if (tail->before == NULL)
  {
    newNode->next = tail->before;
    newNode->before = target;
    tail->before = newNode;
    target->next = newNode;
  }
  else
  {
    target->next=newNode;
    newNode->before = target;
    newNode->next=tail->before;
    tail->before=newNode;
  }
}