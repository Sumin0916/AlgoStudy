#include<iostream>
using namespace std;
int N, M, Q;

class robot{
public:
    int x;
    int y;
    int dx; int dy;
    int yard[1010][1010];
    int remain_grass;

    void action(int _dy, int _dx, int _y, int _x){
        dy = _dy; dx = _dx;
        y = _y; x = _x;
        while(1){
        if (!yard[y][x]) break;
        yard[y][x] = 0;
        remain_grass -= 1;
        if (((y + dy) < 1) || ((y + dy) > N) || ((x + dx) < 1) || ((x + dx) > M)) break;
        x += dx; y += dy;
        }
        return;
    }
    int info(int _y, int _x){
        return !yard[_y][_x];
    }
    int remain(){
        return remain_grass;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    robot obj;
    cin >> N >> M >> Q;
    obj.remain_grass = N*M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            obj.yard[i][j] = 1;
        }
    }
    for(int i=0; i < Q; i++){
        int a, b, c, d, e;
        cin >> a;
        if (a==1) {
            cin >> b >> c >> d >> e;
            obj.action(b, c, d, e);
        }
        else if (a==2) {
            cin >> b >> c;
            cout<<obj.info(b, c)<<'\n';
        }
        else if (a==3) cout<<obj.remain()<<'\n';
    }
    return 0;
}