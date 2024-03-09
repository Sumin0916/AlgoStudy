#include<stdio.h>

void function(int x[3][3], int i){
    for (int j = 0; j < 3; j++){
        int *p = &j[*x];
        int *q = j + x[i];
        if(*p < *q) {
            int* temp = *p;
            *p = *q;
            *q = temp;
        }
    }
}

int main(){
    int arr[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    function(arr, 1);
    function(arr+2, -1);

    for(int i = 0; i < 9; i++){
        printf("%d ", arr[i/3][i%3]);
        if((i%3) == 2) printf('\n');
    }
}