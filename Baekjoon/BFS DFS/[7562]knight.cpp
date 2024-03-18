#include<bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> TP;
const int INF = 987654321;
int B[303][303];
int T, L, kx, ky, gx, gy;
int dx[8] = {2, 2, 1, 1, -2, -2, -1, -1};
int dy[8] = {1, -1, 2, -2, 1, -1, 2, -2};

main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    while(T--){
        cin >> L >> ky >> kx >> gx >> gy;
        queue<TP> Q; Q.push(TP(kx, ky, 0));
        for(int i=0; i<L; i++)for(int j=0; j<L; j++) B[i][j] = INF;
        while(!Q.empty()){
            int x, y, step; tie(x, y, step) = Q.front(); Q.pop();
            if(B[x][y]<=step)continue;
            B[x][y]=step;
            for(int i=0; i<8; i++){
                int nx = x + dx[i]; int ny = y + dy[i];
                if(0<=nx&&nx<L&&0<=ny<L){
                    if(B[nx][ny]>(step+1)) {
                        Q.push(TP(nx, ny, step+1));
                    }
                }
            }
        }
        cout << B[gy][gx] << '\n';
    }
}