#include<bits/stdc++.h>
using namespace std;

int n;
int res = 1;
string ll = "longlong";
string st;

bool isLL(int i) {
    string t = st.substr(i, 8);
    return t == ll;
}

int main() {
    cin >> n; cin >> st;
    int m = 1;
    int ran = 8;
    for (int i = 0; i < n; i++) {
        if (isLL(i)) {
            if (m != 1)++m;
            ran = 8;
        }
        else {
            if (ran < 0) {m = 1;res *= m;}
        }
        --ran;
    }
    cout << res;
}