#include<iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (a+b == c) cout << '+' << '\n';
        else cout << '-' << '\n';
    }
    return 0;
}