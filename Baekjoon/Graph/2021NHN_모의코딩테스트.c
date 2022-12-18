#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b){
  int num1 = *(int *)a;
  int num2 = *(int *)b;
  if (num1 < num2)
    return -1;
  if (num1 > num2)
    return 1;
  return 0;
}
​
void find_array(int size, int row, int col, int *res, int **ary){
  if ((0 <= row && row < size) && (0 <= col && col < size)){
    if (ary[row][col] == 1){
      *res = *res + 1;
      ary[row][col] = 0;
      find_array(size, row+1, col, res, ary);
      find_array(size, row, col+1, res, ary);
      find_array(size, row, col-1, res, ary);
      find_array(size, row-1, col, res, ary);
    return;
    }
  }
  else return;
}

void solution(int sizeOfMatrix, int **matrix) {
  int res_ary[100] = {};
  int last_ind = 0;
  for (int i = 0; i < sizeOfMatrix; i++){
    for (int j = 0; j < sizeOfMatrix; j++){
      if (matrix[i][j] == 1){
        int res = 0;
        find_array(sizeOfMatrix, i, j, &res, matrix);
        res_ary[last_ind] = res;
        last_ind += 1;
      }
    }
  }

  qsort(res_ary, sizeof(res_ary) / sizeof(int), sizeof(int), compare);
  printf("%d\n", last_ind);

  for (int i = 0; i < 100; i++){
    if (res_ary[i] != 0){
      printf("%d ", res_ary[i]);
    }
  }
}


struct input_data {
  int sizeOfMatrix;
  int **matrix;
};

void process_stdin(struct input_data *inputData) {
  int j = 0;
  size_t linecap = 0;
  char *line = NULL, *brkt = NULL, *token = NULL, *sep = " \n";
  getline(&line, &linecap, stdin);
  inputData->sizeOfMatrix = atoi(line);
  inputData->matrix = calloc(inputData->sizeOfMatrix, sizeof(int *));
  for (int i = 0; i < inputData->sizeOfMatrix; i++) {
    getline(&line, &linecap, stdin);
    inputData->matrix[i] = calloc(inputData->sizeOfMatrix, sizeof(int));
    for (j = 0, token = strtok_r(line, sep, &brkt); j < inputData->sizeOfMatrix && token != NULL; j++, token = strtok_r(NULL, sep, &brkt)) {
      inputData->matrix[i][j] = atoi(token);
    }
  }
}

int main() {
  struct input_data inputData;
  process_stdin(&inputData);
  solution(inputData.sizeOfMatrix, inputData.matrix);
  return 0;
}
