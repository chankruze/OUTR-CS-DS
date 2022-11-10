/*
Author: chankruze (chankruze@gmail.com)
Created: Wed Nov 09 2022 21:01:24 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2022 and beyond
*/

#include <stdio.h>

#include "../lib/linked_list.h"
void create(struct node** head, int n) {
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
  struct node* temp = create_node(data);
  // update the head to point to the first node
  *head = temp;

  // loop n - 1 times
  for (size_t i = 2; i <= n; i++) {
    // ask the user for a value to store in {i}th node
    printf("Enter value for node%ld's data: ", i);
    //  store the user input to data varible
    scanf("%d", &data);
    // create {i}th node with value data
    struct node* _node = create_node(data);
    // link prev {i-1}th node's next to {i}th node's address
    temp->next = _node;
    // update temp to hold the {i}th node's address
    temp = _node;
  }
}

// insert a new node at the end of the linked list
void insert_at_end(struct node** head) {
  // create a new node
  int data;
  printf("Enter the value of the new node: ");
  scanf("%d", &data);
  struct node* _node = create_node(data);

  // if node is empty, point head to the new node
  if (is_empty(*head)) {
    *head = _node;
    return;
  }

  struct node* temp = *head;

  while (temp->next) {
    // print_node(temp);
    temp = temp->next;
  }

  temp->next = _node;
}

// insert a new node
void insert_at_start(struct node* head) {
}

// insert a new node at a specific position
void insert_at_position(struct node* head, int position) {
}

// driver function
int main(int argc, char const* argv[]) {
  // head/start of the linked list, default NULL to represent the list is empty
  struct node* head = NULL;
  // number of nodes to create (user input), default to 0
  int n = 0;
  // ask the user to enter a number for n
  printf("How many nodes do you want to create? (i.e. 4): ");
  // save the value of n
  scanf("%d", &n);
  // create linked list
  create(&head, n);
  // print the linked list
  print_linked_list(head);
  // no of new nodes to insert at the end
  int no_of_new_nodes = 1;
  // ask the user to enter a number for n
  printf("How many nodes do you want to insert at the end? (i.e. 1): ");
  scanf("%d", &no_of_new_nodes);
  // insert a new node at the end
  for (size_t i = 0; i < no_of_new_nodes; i++) {
    insert_at_end(&head);
  }
  // print the new linked list
  print_linked_list(head);
  // all ok, exit
  return 0;
}
