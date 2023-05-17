#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

int t, n;
int array[101][101];

void rotate() {
    int temp[101][101];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[j][n-i-1] = array[i][j];
    memcpy(array, temp, sizeof(temp));
}

int main(void){
    cin >> t;
    for (int i = 0; i < t; i++) {
        int res = 0;
        int mirror[101][101] = {0, };
        cin >> n;
        for (int j = 0; j < n; j++){for (int k = 0; k < n; k++){scanf("%1d", &array[j][k]);}}
        for (int j = 0; j < 4; j++){
            for (int m = 0; m < n; m++){
                for (int k = 0; k < n; k++){
                    if (array[m][k] == 1){mirror[m][k] += 1;}
                    else {mirror[m][k] -= 1;}
                }
            }
            rotate();
        }
        for (int m = 0; m < n; m++){
            for (int k = 0; k < n; k++){
                if ((mirror[m][k] <= 0) && (array[m][k] == 1))res++;
                else if ((mirror[m][k] > 0) && (array[m][k] == 0))res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}