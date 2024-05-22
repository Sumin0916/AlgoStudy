#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int n,m; 
set<ll> prime_list;

bool IsPrime (ll n) {
    if (n<2) return false;
    for (ll i=0; i*i<=n; i++) if(n%i==0) return false;
    return true;
}

void Factorize (ll n) {
    if (n==1) return;
    for (ll i=2; i*i<=n; i++) {
        if (n%i!=0) continue;
        while (n%i==0) n/=i;
        prime_list.insert(i);
    }
    if (n!=1) prime_list.insert(n);
    return ;
}


int main () {

    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for (int i=0; i<m; i++) {
        int num; cin >> num;
        Factorize(num);
    }

    cout << min(m, (int) prime_list.size()) << '\n';



    return 0;
}