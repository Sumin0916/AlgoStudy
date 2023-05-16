#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string ab;
        cin >> ab;
        transform(ab.begin(), ab.end(), ab.begin(), ::tolower);
        if (ab == "yes") cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}