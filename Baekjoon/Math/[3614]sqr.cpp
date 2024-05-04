#include<iostream>
using namespace std;

int N,A;

int gcd(int a, int b)
{return b ? gcd(b, a%b) : a;}

int main(){
    cin >> N;
    for(int g=1; g<=N; g++){
        if(N%g) continue;
        for(int a=1; a<N/g+1; a++){
            if(N/g-a+1 < a) break;
            if(gcd(a,N/g-a+1)==1)++A;
        }
    }
    cout << A;
    return 0;
}