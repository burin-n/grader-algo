#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj(1000);
vector<int>friends(1000);

void solve(int S, int K){
	vector<bool> in_queue(1000,false);
	queue<int> q;
	int deg = 0, s, pushed = 1, temp_pushed = 1;
	q.push(S);
	friends[S]++;	
	in_queue[S] = 1;

	while( deg < K ){
		pushed = temp_pushed;
		temp_pushed = 0;
		while(pushed--){
			s = q.front();	
			q.pop();
			for(int t : adj[s]){
				if( !in_queue[t] ){
					friends[S]++;	
					q.push(t);
					temp_pushed++;
					in_queue[t]=1;
				}
			}
		}
		deg++;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int N,E,K,s,t;
	cin >> N >> E >> K;
	for(int i=0;i<E;i++){
		cin >> s >> t;
		adj[s].push_back(t);
		adj[t].push_back(s);
	}
	
	for(int i=0;i<N;i++)
		solve(i,K);	

	int ans = -1;
	for(int i=0;i<N;i++){
		//cout << friends[i] << ' ';
		ans = max(ans,friends[i]);
	}

	cout << ans << endl;

	return 0;
}
