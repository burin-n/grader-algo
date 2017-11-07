#include <bits/stdc++.h>
using namespace std;

int  reach[1000][1000];
int n,t,p, head[1000],r[1000];
vector<int> s(1000,1), adj[1000];

void dfs(int s,int t){
	for(int i : adj[t]){
		if(!reach[s][i]){
		 	reach[s][i] = 1; 
			dfs(s,i);
		}
	}	
}

int findhead(int k){
	if( k == head[k] ) return k;
	else return head[k] = findhead(head[k]);
}

void Union(int a,int b){
	int ha = findhead(a);
	int hb = findhead(b);
	if(ha == hb) return;
	if(r[ha] > r[hb]) head[hb] = ha, s[ha]+=s[hb];
	else head[ha] = hb, s[hb]+=s[ha];
	if(r[ha] == r[hb]) r[hb]++;	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> t;
		for(int j=0;j<t;j++){
			cin >> p;
			adj[i].push_back(p);
		}
	}

	for(int i=0;i<n;i++)
		dfs(i,i);

	for(int i=0;i<n;i++) head[i]=i;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(reach[i][j] && reach[j][i]){
				Union(i,j);	
			}
		}
	}

	multiset<int>ans;
	vector<bool> chead(1000,false);
	for(int i=0;i<n;i++){
		int h = findhead(i);
		if(!chead[h]){
			chead[h] = 1;
			ans.insert(s[h]);
		}
	}

	for(int x : ans)
		cout << x << ' ';
	cout << '\n';
	

	return 0;
}
