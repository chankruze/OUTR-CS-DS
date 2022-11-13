/*
Author: chankruze (chankruze@gmail.com)
Created: Sun Nov 13 2022 08:55:32 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2022 and beyond
*/

#include <stdio.h>

#include "../lib/linked_list.h"

typedef enum sort_order {
  ASCENDING = 1,
  DESCENDING,
  UNSORTED,
} sort_order;

void sort(struct node** head, sort_order order) {
  // if the list is empty print error
  if (*head == NULL) {
    printf("[ERROR] The list is empty.\n");
    return;
  }

  // bubble sort
  struct node *current = *head, *future = NULL;

  // if current node present
  while (current) {
    // get the next node
    future = current->next;

    // if future node is present
    while (future) {
      // check sort order
      switch (order) {
        case ASCENDING:                        /* ascending */
          if (current->data > future->data) {  // swap if current node's data is > next node's data
            int temp = current->data;
            current->data = future->data;
            future->data = temp;
          }
          break;

        case DESCENDING:                       /* descending */
          if (current->data < future->data) {  // swap if current node's data is < next node's data
            int temp = current->data;
            current->data = future->data;
            future->data = temp;
          }
          break;

        default: /* UNSORTED */
          break;
      }

      // update the future to point to the next
      future = future->next;
    }

    // update current to point to the next
    current = current->next;
  }
}

void print_options() {
  printf("**************************\n");
  printf("* %d. ascending\n", ASCENDING);
  printf("* %d. descending\n", DESCENDING);
  printf("* %d. unsorted\n", UNSORTED);
  printf("**************************\n");
}

int main(int argc, char const* argv[]) {
  // 1. create a linked list
  // head/start of the linked list, default NULL to represent the list is empty
  struct node* head = NULL;
  // number of nodes to create (user input), default to 0
  int n = 0;
  // ask the user to enter a number for n
  printf("How many nodes do you want to create? (i.e. 4)\n");
  // save the value of n
  scanf("%d", &n);
  // create linked list
  create_linked_list(&head, n);
  // print the linked list
  print_linked_list(head);
  // print sort order to select
  print_options();
  // take user input for the sort order
  int ord;
  printf("sort order>");
  scanf("%d", &ord);
  // 2. sort the linked list
  sort(&head, ord);
  // print the sorted list
  print_linked_list(head);
  return 0;
}
