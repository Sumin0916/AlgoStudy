#include<iostream>
#include<string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    string s;
    cin >> s;
    cin >> n;
    cout << s[n-1];
    return 0;
}