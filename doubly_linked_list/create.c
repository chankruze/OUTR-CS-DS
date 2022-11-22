/*
Author: chankruze (chankruze@gmail.com)
Created: Tue Nov 22 2022 22:20:34 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2022 and beyond
*/

#include <stdio.h>
#include <stdlib.h>

// node declaration
struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

void print_doubly_node(struct Node *_node) {
  printf("Node {data = %d\tprev = %p\tnext = %p}\n", _node->data, _node->prev, _node->next);
}

int main() {
  // head/start of the linked list
  struct Node *head;

  // create node 1
  struct Node *node1 = malloc(sizeof(struct Node));
  node1->data = 10;
  // create node 2
  struct Node *node2 = malloc(sizeof(struct Node));
  node2->data = 20;
  // create node 3
  struct Node *node3 = malloc(sizeof(struct Node));
  node3->data = 30;
  // create node 4
  struct Node *node4 = malloc(sizeof(struct Node));
  node4->data = 40;
  // create node 5
  struct Node *node5 = malloc(sizeof(struct Node));
  node5->data = 50;

  // link the nodes to create a doubly linked list
  head = node1;
  // update pointers of node1
  node1->prev = NULL;
  node1->next = node2;
  // update pointers of node2
  node2->prev = node1;
  node2->next = node3;
  // update pointers of node3
  node3->prev = node2;
  node3->next = node4;
  // update pointers of node4
  node4->prev = node3;
  node4->next = node5;
  // update pointers of node5
  node5->prev = node4;
  node5->next = NULL;

  // print the doubly linked list (forward traversal)
  struct Node *temp = head;
  struct Node *last = head;

  puts("--- Traversing (Forward Direction) ---");

  while (temp) {
    print_doubly_node(temp);
    last = temp;
    temp = temp->next;
  }

  puts("--- Traversing (Backward Direction) ---");

  // print the doubly linked list (backward traversal)
  while (last) {
    print_doubly_node(last);
    last = last->prev;
  }

  return 0;
}
