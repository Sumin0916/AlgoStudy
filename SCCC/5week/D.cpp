#include<iostream>
#define EVEN true
#define ODD false

using namespace std;
typedef long long ll;

int t, n, q, l, r, k;
bool prefix[200002];
ll num;
bool rs;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> q;
        cin >> num;
        prefix[0] = EVEN;
        if ((num % 2) == 0) prefix[1] = EVEN;
        else prefix[1] = ODD;

        for (int j = 2; j <= n; j++) {
            cin >> num;
            if (((num % 2) == 0) && (prefix[j-1] == ODD)) prefix[j] = ODD;
            else if (((num % 2) == 1) && (prefix[j-1] == EVEN)) prefix[j] = ODD;
            else prefix[j] = EVEN;
        }

        for (int j = 0; j < q; j++) {
            cin >> l >> r >> k;
            ll len = r - l + 1;
            if (((len%2) == 1) && ((k%2) == 1)) rs = ODD;
            else rs = EVEN;

            if (prefix[l-1] == EVEN && rs == EVEN) rs = EVEN;
            else if (prefix[l-1] == ODD && rs == ODD) rs = EVEN;
            else rs = ODD;

            if (prefix[r] != rs) {
                if (prefix[r] != prefix[n]) {
                    if (rs == EVEN) cout << "YES" << '\n';
                    else cout << "NO" << '\n';
                }
                else {
                    if (rs == EVEN) cout << "NO" << '\n';
                    else cout << "YES" << '\n';
                }
            }
            else {
                if (prefix[n] == ODD) cout << "YES" << '\n';
                else if (prefix[n] == EVEN) cout << "NO" << '\n';
            }
        }

    }
    return 0;
}