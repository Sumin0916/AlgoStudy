#include<stdio.h>
#include<algorithm>
using namespace std;
int ans=-1;int b[100]={0,};
main(){
    int N;scanf("%d",&N);
    for(int i=0; i<=N;i++){
        char c;
        scanf("%1c",&c);
        if(c-97<0)continue;
        b[c-97]++;ans=max(b[c-97], ans);
    }
    printf("%d",ans);
}