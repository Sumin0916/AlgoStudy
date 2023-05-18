#include<iostream>
#include<deque>

using ll = long long;
using namespace std;
deque<int> dq;
int n,d;
ll s[100002];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) s[i] += s[i-1];
    ll ans = 0;
    dq.push_back(0);
    for (int i = 1; i <= n; i++) {
        while(!dq.empty() && dq.front() < i-d-1) dq.pop_front();
        ans = max(ans, s[i]-s[dq.front()]);
        while(!dq.empty() && s[dq.back()] > s[i]) dq.pop_back();
        dq.push_back(i);
    }
    cout << ans;
    return 0;
}