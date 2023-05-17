#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> S;
string str_lst[100002], str1, str2;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, res;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> str1;
            str_lst[j] = str1;
            S.insert(str1);
        }
        for (int j = 0; j < n; j++) {
            int s_len = str_lst[j].length();
            str1 = str_lst[j];
            str2.clear();
            res = 0;
            for (int k = 0; k < s_len; k++) {
                str1.erase(str1.begin());
                str2.push_back(str_lst[j][k]);
                if (S.find(str1) != S.end() && S.find(str2) != S.end()) {res = 1;break;}
            }
            cout << res;
        }
        cout << '\n';
        S.clear();
    }
    return 0;
}