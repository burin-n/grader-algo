#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int n;
vector<int> adj[N]; 
vector<ll> child(N),ans(N);
vector<bool> vis(N,0);

void countChild(int s,int p){
	vis[s] = true;
	for(auto t : adj[s]){
			if(t!=p && !vis[t]){
				countChild(t,s);
				child[s] += child[t];
			}
	}

	int res = n;
	for(int t : adj[s]){
		if(t!=p){
			ans[s] +=  (res-child[t])*child[t];
			res -= child[t];
		}
	}
	ans[s] += res-1; 
	child[s]+=1;

}


int main(){
	ios_base::sync_with_stdio(false);
	int s,t;
	cin >> n;
	for(int i=0;i<n-1;i++){
		cin >> s >> t;
		adj[s].push_back(t);
		adj[t].push_back(s);
	}

	countChild(0,-1);
for(int i=0;i<n;i++)
		cout << ans[i] << '\n';

	return 0;
}

