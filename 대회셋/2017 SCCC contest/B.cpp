#include<bits/stdc++.h>
using namespace std;

int N, M, K;
int BF[1010][1010];
int AF[1010][1010];
int CF[1010][1010];

bool is_same_map(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(AF[i][j] != BF[i][j]) return false;
        }
    }
    return true;
}

bool is_visit(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(BF[i][j] != CF[i][j]) return false;
        }
    }
    return true;
}

bool is_full_map(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(!AF[i][j]) return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> K;
    for(int i=0; i<K; i++){
        int x, y; cin >> x >> y;
        BF[x][y] = 1;
    }
    while(true){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                if(BF[i][j]==1){
                    AF[i-1][j-1] = AF[i+1][j-1] = AF[i-1][j+1] = AF[i+1][j+1] = 1;
                }
            }
        }
        if(is_full_map()) {cout << "YES"; return 0; }
        if(is_same_map()||is_visit()) {cout << "NO"; return 0; }
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                CF[i][j] = BF[i][j] = AF[i][j];
                AF[i][j] = 0;
            }
        }
    }
    return 0;
}