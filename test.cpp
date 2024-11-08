#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, ans, i, j;

int main(){
    cin >> n;
    ans = n;
    --n;
    for(i=1;i<=n;i=j+1)
    {
        j=n/(n/i);
        ans+=n/i*(j-i+1);
    }
    cout << ans;
    return 0;
}