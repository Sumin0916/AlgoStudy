#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A[100010];
ll d, d2, n;
ll d1 = -1;
bool r = true;
int main(){
    cin >> n;
    if (n > 2){
        for (int i = 0; i < 2; i++) cin >> A[i];
        d = A[1] - A[0];
        for (int i = 2; i < n; i++) {
            cin >> A[i];
            if (d != A[i] - A[i-1]) { r = false; break; }
        }
    }
    else {
        for (int i = 0; i < n; i++) cin >> A[i];}
    if (!r) {cout << "NO"; return 0;}
    cout << "YES\n";
    d2 = d - d1;
    for (int i = 0; i < n; i++) {
        cout << -A[0]+(i*d1) << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << (2*A[0])+(i*d2) << ' ';
    }
    return 0;
}