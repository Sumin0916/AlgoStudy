#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int H, L, A, B, t, h;
    cin >> H >> L >> A >> B;
    if (A<B)swap(A,B);
    t = sqrt(A*A+B*B);h = (A*B)/t;
    if ((A/2)<=H && B <= L) cout << "YES";
    else if ((B/2)<=H && A <= L) cout << "YES";
    else if (L <= t && H <= h)  cout << "YES";
    else cout << "NO";
    return 0;
}