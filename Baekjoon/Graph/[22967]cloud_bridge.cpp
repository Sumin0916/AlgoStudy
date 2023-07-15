#include<bits/stdc++.h>

using namespace std;
using P = pair<int, int>;

int N;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    int E[N+1][N+1] = {0, };
    vector<P> res;
    int R = 1;

    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        E[a][b] = E[b][a] = 1;
    }
     
    if (2 * (N-1) < N * (N-1) / 2) {
        R = 2;
        for (int i = 2; i <= N; i++) {
            if (E[i][1] == 0) {res.push_back(make_pair(i, 1)); E[i][1] = E[1][i] = 1;}
        }
    }

    else {
        for (int i = 1; i <= N; i++) {
            for (int j = i+1; j <= N; j++) {
                if (E[i][j] == 0) { res.push_back(make_pair(i, j)); E[i][j] = E[j][i] = 1; }
            }
        }
    }

    cout << res.size() << '\n' << R << '\n';

    for (auto &pr : res) {
        cout << pr.first << ' ' << pr.second << '\n';
    }

    return 0;
}