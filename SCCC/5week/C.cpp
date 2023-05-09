#include<iostream>
#include<string>

using namespace std;
int t, n;
int a[27];
int b;
string s;

string solve(){
    for (int j = 0; j < n; j++) {
            if (a[s[j]-'a'] == -1){
                a[s[j]-'a'] = ((b+1)%2);
                b = ((b+1)%2);
            }
            else if (a[s[j]-'a'] == 0) {
                if (b == 0) return "NO";
                b = 0;
            }
            else {
                if (b == 1) return "NO";
                b = 1;
            }
    }
    return "YES";
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int i = 0; i < t; i++) {
        fill_n(a, 27, -1);
        cin >> n;
        cin >> s;
        cout << solve() << '\n';
    }   
    return 0;
}