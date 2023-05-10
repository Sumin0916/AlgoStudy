#include<iostream>
#include<string>

using namespace std;

string query(int n) {
    cout << n << endl;
    string re; cin >> re;
    return re;
}

void solve() {
    int s = 1; int l = 1000000;
    while (s <= l) {
        int mid = (s + l)/2;
        if (query(mid) == ">=") s = mid+1;
        else l = mid-1;
    }
    cout << "! " << l << endl; 
}

int main(void){
    solve();
    return 0;
}