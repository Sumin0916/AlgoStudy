#include<iostream>
#include<bits/stdc++.h>

using namespace std;
using pp= tuple<int, int, int>;
int H, W, num;

int cuttingBrownie() {

}

int main(){
    cin >> H >> W;
    cin >> num;
    vector<pp> pieces;
    for(int i=0,a,b,c; i<num; ++i){
        cin >> a >> b >> c;
        pieces.emplace_back(a, b, c);
    }
    cout << cuttingBrownie() << endl;
    return 0;
}