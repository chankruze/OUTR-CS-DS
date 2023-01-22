/*
Author: chankruze (chankruze@gmail.com)
Created: Sun Jan 22 2023 21:45:04 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2023 and beyond
*/

#include <stdio.h>

#define MAX 5

int FRONT = -1, REAR = -1, QUEUE[MAX];

int is_empty() {
  if (FRONT == REAR && FRONT == -1) return 1;
  return 0;
}

int is_full() {
  if (REAR == MAX - 1) return 1;
  return 0;
}

void enqueue(int data) {
  if (is_full()) {
    puts("Overflow: queue is full");
    return;
  }

  if (is_empty()) {
    FRONT++;
    REAR++;
    QUEUE[REAR] = data;
    printf("Inserted: %d | Front: %d | Rear: %d\n", data, FRONT, REAR);
    return;
  }

  QUEUE[++REAR] = data;
  printf("Inserted: %d | Front: %d | Rear: %d\n", data, FRONT, REAR);
}

void dequeue() {
  if (is_empty()) {
    puts("Underflow: queue is already empty.");
    return;
  }

  int data = QUEUE[FRONT++];
  printf("Deleted: %d | Front: %d | Rear: %d\n", data, FRONT, REAR);
}

void print() {
  printf("QUEUE: ");
  for (int i = FRONT; i <= REAR; i++) {
    printf("%d ", QUEUE[i]);
  }
  printf("\n");
}

int main() {
  enqueue(100);
  enqueue(200);
  enqueue(300);
  enqueue(400);
  enqueue(500);
  print();

  dequeue();
  dequeue();
  dequeue();

  print();
  return 0;
}