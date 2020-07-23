#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct Node {
  struct Node* before;
  int data[3];
  struct Node* next;
};

void addNode(struct Node* target, int* data);
void printNode(struct Node* target);

void main() {
  
}