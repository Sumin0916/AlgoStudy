#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int H, L, A, B, t;
    cin >> H >> L >> A >> B;
    t = sqrt(A*A+B*B);
    if (A<B)swap(A,B);
    if ((A/2) <= H && B <= L) cout << "YES";
    else if ((B/2) <= H && A <= L) cout << "YES";
    else if ((A*B)/t <= H && t <= L) cout << "YES";
    else cout << "NO";
    return 0;
}