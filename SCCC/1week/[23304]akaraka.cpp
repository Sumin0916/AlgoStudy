#include <iostream>
#include <string>

using namespace std;

bool is_aka(string str, int end){
    if (0 >= end){return true;}
    int str_len = end+1;
    for (int i = 0; i < str_len; i++){
        if (str[i] != str[end-i]){return false;}
    }
    return is_aka(str.substr(0, str_len/2), (str_len/2)-1);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;

    cin>> str;
    if (is_aka(str, str.length()-1)){
        cout<<"AKARAKA";
    }
    else{
        cout<<"IPSELENTI";
    }   
}