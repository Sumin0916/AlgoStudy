#include <iostream>
#include <string>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        int r = 0;
        string s;
        bool v[52] = {false, };
        cin >> n;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (v[s[j]-'A'] == true) r++;
            else {
                v[s[j]-'A'] = true;
                r += 2;
            }
        }
        cout << r << endl;
    }
    return 0;
}