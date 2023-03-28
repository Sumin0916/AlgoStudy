#include <iostream>

using namespace std;
int res=0;
int main(void){
    int t;
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 5; i++){
        cin>>t;
        if(t>=40){res+=t;}
        else{res+=40;}
    }
    cout<<res/5;
    return  0;
}