#include<iostream>
#include<deque>

using namespace std;
int N, K, L;
int board[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class snake {
    public:
        deque<pair<int, int>> bodys;
        deque<pair<int, char>> time_q;
        int degree = 1;
        int t = 1;

        int step(){
            pair<int, int> head = bodys.front();
            pair<int, int> tail = bodys.back();
            head.first += dx[degree]; head.second += dy[degree];
            if(board[head.first][head.second] == 1) return 1;
            if(board[head.first][head.second] != 2){
                board[tail.first][tail.second] = 0;
                bodys.pop_back();
            }
            bodys.push_front(head);
            board[head.first][head.second] = 1;
            return 0;
        }

        void orient(){
            pair<int, char> check = time_q.front();
            if(t == check.first){
                if(check.second == 'D') degree += 3;
                else degree += 1;
                degree %= 4;
                time_q.pop_front();
            }
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    snake obj;
    obj.bodys.push_back(make_pair(1, 1));
    cin >> N;
    for(int i=0; i <= (N+1); i++)for(int j=0; j <= (N+1); j++)if((i==0) || (j==0) || (i==(N+1)) || (j==(N+1)))board[i][j] = 1;

    cin >> K;
    for(int i = 0; i < K; i++){
        int a, b;
        cin >> a >> b; board[a][b] = 2;
    }
    cin >> L;
    for(int i = 0; i < L; i++){
        int a; char b;
        cin >> a >> b; obj.time_q.push_back(make_pair(a, b));
    }
    while(1){
        if(obj.step()) break;
        obj.orient();
        obj.t += 1;
    }
    cout << obj.t;
    return 0;
}