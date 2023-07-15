#include<bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << (e*c-b*f)/(a*e-b*d) << ' ' << (a*f-d*c)/(a*e-b*d);
    return 0;
}