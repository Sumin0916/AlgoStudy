#include <iostream>

using namespace std;

int res[30] = {0, };

int main(void){
    int t;
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (int i = 0; i < 28; i++){
        int a; cin >> a; res[a-1] = 1;
    }
    for (int i = 0; i < 30; i++) {
        if(res[i] == 0){cout << i+1 << '\n';}
    }
    return  0;
}