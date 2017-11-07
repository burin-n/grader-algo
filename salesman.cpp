#include <bits/stdc++.h>
using namespace std;
vector<int> q(1001,0);
vector<int> qs(1001,0);
int n,m,t,ds,dt;

int gtime(int s,int t){
	if(s>t) swap(s,t);
	return min( qs[t]-qs[s] , qs[m]-qs[t]+qs[s]);
}

int solve(int s,int t){
	int w1 = gtime(s,t);
 	int w2 = gtime(s,ds) + gtime(dt,t);
	int w3 = gtime(s,dt) + gtime(ds,t);	
	return min(w1,min(w2,w3));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=0;i<m;i++)
		cin >> q[i]; 
	q[m] = q[0];
	for(int i=1;i<=m;i++){
		cin >> t;
		qs[i] = qs[i-1]+t;
	}

	while(n--){
		cin >> ds >> dt;
		if( ds > dt ) swap(ds,dt);
		int ans = 0;
		for(int i=0;i<m;i++){
			ans += solve(q[i],q[i+1]);	
		}	
		cout << ans << endl;
	}

	return 0;
}

