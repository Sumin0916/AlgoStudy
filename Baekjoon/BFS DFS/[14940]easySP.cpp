#include<bits/stdc++.h>

using namespace std;

enum position
{
    DONTGO = 0,
    GO,
    GOAL
};
int arr[1001][1001];
int n, m;

int bfs(int r, int c, int w) {
    if (arr[r][c] == 2) return w;
    if (arr[r][c] == 1){
    if (r-1 > -1) return bfs(r-1, c, w+1);
    if (r+1 < n) return bfs(r+1, c, w+1);
    if (c-1 > -1) return bfs(r, c-1, w+1);
    if (c+1 < m) return bfs(r, c+1, w+1);
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            arr[i][j] = bfs(i, j, 0);
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}