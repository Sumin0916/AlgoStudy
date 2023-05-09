#include<iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n, a, r;
    cin >> t;
    for (int i = 0;  i < t; i++) {
        cin >> n;
        r = 0;
        for (int j = 0; j < n; j++) {
            cin >> a;
            if ((a%2)==0) {r += a;}
            else {r -= a;}
        }
        if (r>0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}