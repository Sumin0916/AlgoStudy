#include<iostream>

using namespace std;

int main() {
    int a, b, n;
    cin >> n >> a >> b;
    if (a > b) cout << "Subway";
    else if (a < b) cout << "Bus";
    else cout << "Anything";
    return 0;
}