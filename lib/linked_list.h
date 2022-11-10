/*
Author: chankruze (chankruze@gmail.com)
Created: Wed Nov 09 2022 20:20:26 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2022 and beyond
*/

#include <stdlib.h>

struct node {
  int data;          /* integer value */
  struct node *next; /* address of the next node */
};

void print_linked_list(struct node *head) {
  // if the linked list is empty then head will be NULL
  if (head == NULL) {
    printf("Linked list is empty.");
    return;
  }

  struct node *current_node = head; /* point current node to first node's address */
  int index = 1;                    /* loop counter */

  printf("------ Linked List [start] ------\n");
  while (current_node != NULL) {
    printf("#%d\t[%p]\t{data = %d\t| next = %p}\n", index, current_node, current_node->data, current_node->next);
    current_node = current_node->next; /* update current node address */
    index++;                           /* update loop counter */
  }
  printf("------- Linked List [end] -------\n");
}

struct node *create_node(int data) {
  struct node *_node = malloc(sizeof(struct node));
  _node->data = data;
  _node->next = NULL;
  return _node;
}

int is_empty(struct node *head) {
  return head == NULL;
}

void print_node(struct node *_node) {
  printf("node {data = %d, next = %p}\n", _node->data, _node->next);
}

int count_nodes(struct node *head) {
  int count = 0;

  struct node *current_node = head;

  while (current_node) {
    current_node = current_node->next;
    count++;
  }

  return count;
}

void create_linked_list(struct node **head, int n) {
  // if user input is 0, exit
  if (n == 0) {
    printf("exiting...");
    exit(-1);
  }

  // temp varible to store user data for new node's data
  int data;
  // ask the user for a value to store in first node
  printf("Enter value for node1's data: ");
  // store the value to the data variable
  scanf("%d", &data);
  // create first node and hold it's address in a temp pointer
  struct node *temp = create_node(data);
  // update the head to point to the first node
  *head = temp;

  // loop n - 1 times
  for (size_t i = 2; i <= n; i++) {
    // ask the user for a value to store in {i}th node
    printf("Enter value for node%ld's data: ", i);
    //  store the user input to data varible
    scanf("%d", &data);
    // create {i}th node with value data
    struct node *_node = create_node(data);
    // link prev {i-1}th node's next to {i}th node's address
    temp->next = _node;
    // update temp to hold the {i}th node's address
    temp = _node;
  }
}