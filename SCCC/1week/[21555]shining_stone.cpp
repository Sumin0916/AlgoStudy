#include <iostream>
#include <vector>

using namespace std;

long a[200040], b[200040];
int n, k;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    for (int i = 0; i < n; i++)cin>>a[i];
    for (int i = 0; i < n; i++)cin>>b[i];
    for (int i = 1; i < n; i++){
        a[i] = min(a[i-1], b[i-1]+k)+a[i];
        b[i] = min(a[i-1]+k, b[i-1])+b[i];
    }
    cout<<min(a[n-1], b[n-1]);
    return 0;
}