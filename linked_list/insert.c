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
void insert_at_start(struct node** head) {
  // create a new node
  int data;
  printf("Enter the value of the new node: ");
  scanf("%d", &data);
  struct node* _node = create_node(data);
  // check if the list is empty
  // if so, then update head to point to the new node
  if (is_empty(*head)) {
    *head = _node;
    return;
  }

  // if the list is not empty then point the head to
  // the new node as well as point the new node to
  // the previous 1st node's location
  struct node* prev_first = *head;
  *head = _node;
  _node->next = prev_first;
}

// insert a new node at a specific position
void insert_at_position(struct node** head, int position) {
  // create a new node
  int data;
  printf("Enter the value of the new node: ");
  scanf("%d", &data);

  // check if the given position is valid or not
  // check if the list is empty
  if (is_empty(*head)) {
    printf("[ERROR] List is empty. Can't add %d at %dth position\n", data,
           position);
    return;
  }

  // count total nodes
  int total_nodes = count_nodes(*head);
  // if the desired position is out of bound
  if (position > total_nodes) {
    printf(
        "[ERROR] Total %d nodes present. %dth node can't be created.\n",
        total_nodes, position);
    return;
  }

  struct node* _node = create_node(data);

  // if the list is not empty then traverse the list upto (position-1)th location
  // and storing the prev node in a temp node* then,
  // 1. update new node's next to {position-1}th node's link (previously {position}th node's address)
  // 2. update {position-1}th node's next to point to new node's address

  if (position == 1) {
    _node->next = *head;
    *head = _node;
    return;
  }

  struct node* prev = *head;

  for (size_t i = 1; i < position - 1; ++i) {
    prev = prev->next;
  }

  // update new node's next to {position-1}th node's link (previously nth node's address)
  _node->next = prev->next;
  // fix {position-1}th node's next to point to new node's address
  prev->next = _node;
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
  // no of new nodes to insert at the end/start
  int no_of_new_nodes = 0;
  /**
   * insert at the end
   */
  // ask the user to enter a number for no_of_new_nodes
  printf("How many nodes do you want to insert at the end? (i.e. 1): ");
  scanf("%d", &no_of_new_nodes);
  // insert a new node at the end
  for (size_t i = 0; i < no_of_new_nodes; i++) {
    insert_at_end(&head);
  }
  // print the new linked list
  print_linked_list(head);
  /**
   *  insert at the start
   */
  // ask the user to enter a number for no_of_new_nodes
  printf("How many nodes do you want to insert at the start? (i.e. 1): ");
  scanf("%d", &no_of_new_nodes);
  // insert a new node at the end
  for (size_t i = 0; i < no_of_new_nodes; i++) {
    insert_at_start(&head);
  }
  // print the new linked list
  print_linked_list(head);
  /**
   *  insert at the start
   */
  // ask the user to enter a number for no_of_new_nodes
  int position;
  printf("At which position do you want to insert a new node? (min: 1): ");
  scanf("%d", &position);
  // insert a new node at the given position
  insert_at_position(&head, position);
  // print the new linked list
  print_linked_list(head);
  // all ok, exit
  return 0;
}
