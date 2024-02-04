#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct pp {
    int cost=-1;
    int arr[50]={0, };

    bool operator<(const pp& other) const {
        if(cost < other.cost) return true;
        else if(cost == other.cost) accumulate(arr, arr+50, 0) < accumulate(other.arr, other.arr+50, 0);
        return false;
    }
    pp add_pp(const pp& other) const{
      pp result;
      result.cost = cost + other.cost;
      for(int i=0;i<50;i++)result.arr[i]=arr[i]+other.arr[i];
      return result;
    }
};
int H,W,N;
pp DP[202][202];

pp combi(int h, int w){
  if(h<=0||w<=0) return DP[0][0];
  if(DP[h][w].cost!=-1) return DP[h][w];
  for(int i=1;i<=h;i++){
      DP[h][w] = max({(combi(h-i, w).add_pp(DP[i][w])), DP[h][w]});
    }
  for (int j=1;j<=w;j++){
    DP[h][w] = max({ (combi(h, w-j).add_pp(DP[h][j])), DP[h][w]});
  }
  return DP[h][w];
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  cin >> H >> W; cin >> N;
  for(int i=0,a,b,c;i<N;i++){cin >> a >> b >> c; ++DP[a][b].arr[i];DP[a][b].cost=c;}
  combi(H, W);
  cout << DP[H][W].cost <<'\n';
  for(int i=0;i<N;i++) cout << DP[H][W].arr[i] << ' ';
  return 0;
}