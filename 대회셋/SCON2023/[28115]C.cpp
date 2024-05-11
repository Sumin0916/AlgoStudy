#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N,a,b,c, da;
    cin >> N;
    cin >> a >> b; da = b-a;
    for(ll i=0; i<N-2; i++) {cin>>c;if(c-b!=da){cout<<"NO";return 0;}b=c;}
    cout<<"YES\n";
    for(ll i=0; i<N; i++) cout<<a+i*da<<' ';
    cout<<'\n';
    for(ll i=0; i<N; i++) cout<<0<<' ';
    return 0;
}