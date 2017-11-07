#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<int> adj[100000], state(100000,0);
int ans;

ii dfs(int s,int p){
	state[s] = 1;
	ii ret = ii(-1,-1);;
	for(int t : adj[s]){
		if(t == p || state[t] == 2) continue;
		if(state[t] == 1){
		 	return ii(1,t);
		}

		ii temp = dfs(t,s);
		if(temp.second == s){
			ans = temp.first+1;
			return ret;
		}
		if(temp.second>=0){
			return ii(temp.first+1,temp.second);
		}
		else ret = temp; 

	}	
	state[s] = 2;
	return ret;
}


int main(){
	int n,x,y;
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	ii temp;
	for(int i=0;i<n && ans==0;i++){
		if(state[i] == 0){
			dfs(i,-1);
		}
	}
	cout << ans << endl;
	return 0;
}
