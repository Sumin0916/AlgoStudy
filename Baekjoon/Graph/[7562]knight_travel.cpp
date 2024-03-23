#include<bits/stdc++.h>
using namespace std;
int T,L; 
int kx, ky, gx, gy;
int G[303][303];
void knight(int x, int y, int G[][303], int step){
    if(x<0||x>=L||y<0||y>=L) return;
    if(G[x][y] < step) return;
    G[x][y] = step;
    knight(x+1, y+2, G, step+1); knight(x+1, y-2, G, step+1); knight(x-2, y+1, G, step+1); knight(x-2, y-1, G, step+1);
    knight(x+2, y+1, G, step+1); knight(x+2, y-1, G, step+1); knight(x-1, y+2, G, step+1); knight(x-1, y-2, G, step+1);
}

main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>T;
    while(T--){
        for(int i=0; i<L; i++)for(int j=0; j<L; j++)G[i][j]=999999;
        cin>>L >> kx >> ky >> gx >> gy;
        knight(kx, ky, G, 0);
        for(int i=0; i<L; i++){
            for(int j=0; j<L; j++){
                cout << G[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << G[gx][gy] << '\n';
    }
}