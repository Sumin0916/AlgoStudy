#include<iostream>
using namespace std;

int a,b;

int gcd(int a, int b)
{return b ? gcd(b, a%b) : a;}

int main(){
    cin >> a >> b;
    cout << a+b-gcd(a,b);
    return 0;
}