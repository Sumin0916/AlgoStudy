#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int cuttingBrownie() {

}

int main(){
    int h, w, price, num;
    cin >> h >> w;
    cin >> num;
    vector<vector<int>> pieces;
    for(int i=0; i<num; ++i){
        vector<int> piece;
        cin >> h >> w >> price;
        piece.push_back(h);
        piece.push_back(w);
        piece.push_back(price);
        pieces.push_back(piece);
    }
    cout << cuttingBrownie() << endl;
    return 0;
}