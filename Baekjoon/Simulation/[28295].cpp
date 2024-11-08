#include<bits/stdc++.h>
using namespace std;
typedef vector<pair<int,int>> TP;
int N, M;
int ans = 100;
int arrys[10][10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<tuple<int, int, int>> cctvs;
int cctv_num;

TP bim(int x, int y, int dir, int arr[][10]){
    int ddx = dx[dir]; int ddy = dy[dir];
    TP narr;
    while(true){
        int nx = x + ddx; int ny = y + ddy;
        if(!((0 <= nx && nx < N) && (0<= ny && ny < M)) || arr[nx][ny] == 6){
            return narr;
        }
        if(arr[nx][ny] == 0){
            arr[nx][ny] = -1;
            narr.emplace_back(make_pair(nx, ny));
        }
        x = nx;
        y = ny;
    }
    return narr;
}

TP cctv(int type, int x, int y, int dir, int arr[][10]){
    TP narr;
    switch (type) {
    case 1: {
        TP t1 = bim(x, y, dir, arr);
        narr.insert(narr.end(), t1.begin(), t1.end());
        break;
    }
    case 2: {
        TP t1 = bim(x, y, dir, arr);
        TP t2 = bim(x, y, (dir+2)%4, arr);
        narr.insert(narr.end(), t1.begin(), t1.end());
        narr.insert(narr.end(), t2.begin(), t2.end());
        break;
    }
    case 3: {
        TP t1 = bim(x, y, dir, arr);
        TP t2 = bim(x, y, (dir+1)%4, arr);
        narr.insert(narr.end(), t1.begin(), t1.end());
        narr.insert(narr.end(), t2.begin(), t2.end());
        break;
    }
    case 4: {
        TP t1 = bim(x, y, dir, arr);
        TP t2 = bim(x, y, (dir+1)%4, arr);
        TP t3 = bim(x, y, (dir+2)%4, arr);
        narr.insert(narr.end(), t1.begin(), t1.end());
        narr.insert(narr.end(), t2.begin(), t2.end());
        narr.insert(narr.end(), t3.begin(), t3.end());
        break;
    }
    case 5: {
        TP t1 = bim(x, y, dir, arr);
        TP t2 = bim(x, y, (dir+1)%4, arr);
        TP t3 = bim(x, y, (dir+2)%4, arr);
        TP t4 = bim(x, y, (dir+3)%4, arr);
        narr.insert(narr.end(), t1.begin(), t1.end());
        narr.insert(narr.end(), t2.begin(), t2.end());
        narr.insert(narr.end(), t3.begin(), t3.end());
        narr.insert(narr.end(), t4.begin(), t4.end());
        break;
    }
    }
    return narr;
}

void squar_arr(int arr[][10]){
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 0){
                cnt++;
            }
        }
    }
    ans = min(ans, cnt);
    return;
}

void solve(int num){
        if(num == cctv_num) {
            squar_arr(arrys);
            return;
        }
        
        int type = get<0>(cctvs[num]);
        int max_dir = 4;
        
        if(type == 2) max_dir = 2;
        else if(type == 5) max_dir = 1;
        
        for(int j = 0; j < max_dir; j++){
            TP changes = cctv(get<0>(cctvs[num]), get<1>(cctvs[num]), get<2>(cctvs[num]), j, arrys);
            solve(num+1);
            for(auto i : changes){
                arrys[i.first][i.second] = 0;
            }
        }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arrys[i][j];
            if(1 <= arrys[i][j] && arrys[i][j] <= 5){
                cctvs.emplace_back(arrys[i][j], i, j);
            }
        }
    }
    cctv_num = cctvs.size();
    solve(0);
    cout << ans;
    return 0;
}