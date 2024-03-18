#include<iostream>
using namespace std;main(){int a,b=2;cin>>a;while(a>1){if(!(a%b)){cout<<b<<'\n';a/=b;}else b++;}}