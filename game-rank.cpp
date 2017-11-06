#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector< vector<int> > adj(5000), iadj(5000);
vector<ii> finish(5000);
vector<bool> visit(5000,false), ivisit(5000,false);
vector<int> Rank,temp_rank;
int N,P,a,b,t;

void idfs(int p){
	t++;
	ivisit[p] = true;
	for(int e : iadj[p])
		if(!ivisit[e])
			idfs(e);	
	finish[p].first = -t;	
	finish[p].second = p;
}

void dfs(int p,int r){

}

void SCC(){
	t=0;
	for(int i=0;i<N;i++)
		if(!ivisit[i])
			idfs(i);
	sort(finish.begin(),finish.begin()+N);
	for(int i=0;i<N;i++){
		if(!visit[i]){
			temp_rank.clear();
			dfs(finish[i].second,1);
		}
	}	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> N >> P;
	for(int i=0;i<P;i++){
		cin >> a >> b;
		adj[a].push_back(b);
		iadj[b].push_back(a);
	}

	SCC();

	return 0;
}
