#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
struct a{
	int d,e,l;
	bool operator <(const a &o)const{
		return d<o.d;
	}
}s[200001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k,e,l;
	queue<int> wait,stock;

	cin >> n >> m >> k;
	for(int i=0;i<k;i++){
		cin >> s[i].d >> s[i].e >> s[i].l;
	}
	sort(s,s+k);
	for(int i=0;i<k;i++){
		e = s[i].e;
		l = s[i].l;
		if(e == 0){
			if(!wait.empty()) cout << wait.front() << endl,wait.pop();
			else cout << 0 << endl, stock.push(l);
		}
		else{
			if(!stock.empty()) cout << stock.front() << endl,stock.pop();
			else cout << 0 << endl, wait.push(l);
		}
	}
	return 0;
}



