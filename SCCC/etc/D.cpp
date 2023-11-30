#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
    int D[12][11];
    string x1 = "revgniaton";
    string x = "recognition";
    for (int i=0; i < 12;i++)D[i][0] = i*2;
    for (int j=0; j < 11;j++)D[0][j] = j;

    for (int j = 1; j < 12;j++){
        for (int i = 1; i < 11;i++){
            int scost=1;
            if (x1[i-1]==x[j-1])scost=0;
            D[j][i] = min({D[j-1][i]+2, D[j][i-1]+1, D[j-1][i-1]+scost});
        }
    }

    for (int j=0; j < 12;j++){
        for (int i = 0; i < 11;i++){
            cout << setw(3) << D[j][i] << " ";
        }
        cout << '\n';
    }
    return 0;
} 