#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
    int D[19][17];
    string x1 = "1107666554117701";
    string x = "100766555541707700";
    for (int i=0; i < 19;i++)D[i][0] = i;
    for (int j=0; j < 17;j++)D[0][j] = j;

    for (int j = 1; j < 19;j++){
        for (int i = 1; i < 17;i++){
            int scost=1;
            if (x1[i]==x[j])scost=0;
            D[j][i] = min({D[j-1][i]+1, D[j][i-1]+1, D[j-1][i-1]+scost});
        }
    }

    for (int j=0; j < 19;j++){
        for (int i = 0; i < 17;i++){
            cout << setw(3) << D[j][i] << " ";
        }
        cout << '\n';
    }
    return 0;
} 