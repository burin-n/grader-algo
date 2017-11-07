#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
vector<int> visit(1000,0);

bool dfs(int p,int s){
	bool ret = false;
	visit[s] = 1;
	for(int t : adj[s] ){
		if( t == p || visit[t] == 2) continue;
		if( visit[t] == 1 ) return true;
		ret = ret || dfs(s,t);	
	}	
	visit[s] = 2;
	return ret;
}

string checkCycle(int n){
	for(int i=0;i<1000;i++) visit[i] = 0;

	for(int i=0;i<n;i++){
		if(visit[i] == 0)
			if(dfs(-1,i)) return "YES";
	}

	return "NO";
}

int main(){
	ios_base::sync_with_stdio(0);
	int T,s,t,N,E;
		
	cin >> T;
	while(T--){
		cin >> N >> E;
		for(int i=0;i<1000;i++)
			adj[i].clear();

		for(int i=0;i<E;i++){
			cin >> s >> t;
			adj[s].push_back(t);
			adj[t].push_back(s);
		}
		cout << checkCycle(N) << endl;
	}	

	return 0;
}
