#include <iostream>
#include <string>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        int cyper[102];
        cin >> n;
        for (int j = 0; j < n; j++) {cin >> cyper[j];}
        for (int j = 0; j < n; j++) {
            int l;
            string s;
            cin >> l >> s;
            for (int k = 0; k < l; k++) {
                if (s[k] == 'U') {cyper[j] = (cyper[j]+9) % 10;}
                else {cyper[j] = (cyper[j]+1) % 10;}
            }
        }
        for (int j = 0; j < n; j++) {cout << cyper[j] << ' ';}
        cout << endl;
    }
    return 0;
}