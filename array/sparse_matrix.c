/*
Author: chankruze (chankruze@gmail.com)
Created: Mon Nov 14 2022 19:40:00 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2022 and beyond
*/

#include <stdio.h>

int main(int argc, char const *argv[]) {
  int row_size, column_size;
  printf("Enter the no. of rows: ");
  scanf("%d", &row_size);
  printf("Enter the no. of columns: ");
  scanf("%d", &column_size);

  int matrix[row_size][column_size];

  for (int i = 0; i < row_size; i++) {
    for (int j = 0; j < column_size; j++) {
      printf("Enter the value for [%d][%d]: ", i, j);
      scanf("%d", &matrix[i][j]);
    }
  }

  // 1. print the 2d array and calculate the no. of non zero elements
  int non_zero_count = 0;
  // traverse and check each value
  for (int i = 0; i < row_size; i++) {
    for (int j = 0; j < column_size; j++) {
      printf("%d\t", matrix[i][j]);
      // check if the value is non zero
      if (matrix[i][j]) {
        non_zero_count++;
      }
    }
    printf("\n");
  }

  // 2. check if no of non zero elememts are less than half
  // or, check the no of zeros are greater than half
  if (non_zero_count < ((row_size * column_size) / 2)) {
    printf("The given matrix is a sparse matrix.\n");
  }

  // 2. convert sparse matrix to 3-tuple method
  int three_tuple[non_zero_count + 1][3];

  // first row in the 3-tuple [total_rows, total_columns, no_of_non_zero_elements]
  three_tuple[0][0] = row_size;
  three_tuple[0][1] = column_size;
  three_tuple[0][2] = non_zero_count;

  // set the working row index
  int working_row = 1;

  // traverse and push the non zero elements
  for (int i = 0; i < row_size; i++) {
    for (int j = 0; j < column_size; j++) {
      // check if the value is non zero
      if (matrix[i][j]) {
        three_tuple[working_row][0] = i;             // row index
        three_tuple[working_row][1] = j;             // column index
        three_tuple[working_row][2] = matrix[i][j];  // the value
        working_row++;                               // increment the working row index of 3-tuple
      }
    }
  }

  // print the 3-tuple array
  printf("The 3-tuple form of the given sparse matrix is:\n");
  for (int i = 0; i < working_row; i++) {  // or i < non_zero_count + 1
    for (int j = 0; j < 3; j++) {
      printf("%d\t", three_tuple[i][j]);
    }
    printf("\n");
  }

  return 0;
}
