#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int sqrtN = 1024;

struct Query{
	int idx, s, e;

	bool operator < (Query &x){
		if(s/sqrtN != x.s/sqrtN) return s/sqrtN < x.s/sqrtN;
		return e < x.e;
	}
};

vector<int> v, tmp;
vector<Query> query;
int n, q;
int cnt[1010101];
int scnt[1010101];
vector<int> ans;
int res;

void sub(int i){
	scnt[cnt[i]]--;
	if (cnt[i] == res && !scnt[cnt[i]]) res--;
	cnt[i]--;
	scnt[cnt[i]]++;
}

void add(int i){
	if(cnt[i] != 0) scnt[cnt[i]]--;
	cnt[i]++;scnt[cnt[i]]++;
	res = max(res, cnt[i]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	cin >> n; v.resize(n+1);
	for(int i=1; i<=n; i++) cin >> v[i];
	cin >> q;
	for(int i=0; i<q; i++){
		int b, c;
		cin >> b >> c;
		query.push_back({i, b, c});
	}
	sort(query.begin(), query.end());

	int s = query[0].s;
	int e = query[0].e;
	int idx = query[0].idx;
	for(int i=s; i<=e; i++) add(i);
	ans[idx] = now;

	for(int i=1; i<q; i++){
		idx = query[i].idx;
		while(s < query[i].s) sub(s++);
		while(s > query[i].s) add(--s);
		while(e < query[i].e) add(++e);
		while(e > query[i].e) sub(e--);
		ans[idx] = now;
	}

	for(auto i : ans) cout << i << "\n";
}