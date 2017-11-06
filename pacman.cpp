#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int INF = 1e9;

int T,K,R,C,N,tb[100][100],gt[100],gr[100],gc[100], ptb[100][100];
string ctb[100];

bool isValid(int r,int c){
	if(r >= 0 && c>=0 && r<R && c<C)
		if(ctb[r][c] == '.')
			return true;
	return false;
}

void bfs(int index){
	queue<ii> q;
	vector< vector<bool>> inQ(100,vector<bool>(100,false));
	q.push(ii(gr[index],gc[index]));

	int r,c,t,pushed,count_pushed;
	count_pushed = 0;
	t = gt[index];
	pushed = 1;
	ii s;
	
	while(!q.empty()){
		while(pushed--){
			s = q.front();
			q.pop();
			r = s.first;
			c = s.second;
			if(tb[r][c] <= t) continue;
			tb[r][c] = t;
			if(isValid(r-1,c) && !inQ[r-1][c] && tb[r-1][c] > t+1 ){
				q.push(ii(r-1,c));
				inQ[r-1][c] = 1;
				count_pushed++;
			}
			if(isValid(r,c-1) && !inQ[r][c-1] && tb[r][c-1] > t+1 ){
				q.push(ii(r,c-1));
				inQ[r][c-1] = 1;
				count_pushed++;
			}
			if(isValid(r+1,c) && !inQ[r+1][c] && tb[r+1][c] > t+1){
				q.push(ii(r+1,c));
				inQ[r+1][c] = 1;
				count_pushed++;
			}
			if(isValid(r,c+1) && !inQ[r][c+1] && tb[r][c+1] > t+1){
				q.push(ii(r,c+1));
				inQ[r][c+1] = 1;
				count_pushed++;
			}
		}
		t++;
		pushed = count_pushed;
		count_pushed = 0;
	}
}

bool dfs(int r,int c,int t){
	bool ans = false;
	if(tb[r][c] <= t) return false;
	if(tb[r][c] > T) return true;
	ptb[r][c] = t;
	if( isValid(r-1,c) && tb[r-1][c]>t+1 && ptb[r-1][c]>t+1) ans |= dfs(r-1,c,t+1); 
	if( isValid(r+1,c) && tb[r+1][c]>t+1 && ptb[r+1][c]>t+1) ans |= dfs(r+1,c,t+1); 
	if( isValid(r,c-1) && tb[r][c-1]>t+1 && ptb[r][c-1]>t+1) ans |= dfs(r,c-1,t+1); 
	if( isValid(r,c+1) && tb[r][c+1]>t+1 && ptb[r][c+1]>t+1) ans |= dfs(r,c+1,t+1); 
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	int pr,pc;
	cin >> K;
	while(K--){
		cin >> R >> C >> N >> T >> pr >> pc;
		
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				tb[i][j] = ptb[i][j] = INF;

		for(int i=0;i<N;i++)
			cin >> gt[i] >> gr[i] >> gc[i];
		
		for(int i=0;i<R;i++)
			cin >> ctb[i];
		
		for(int i=0;i<N;i++)
			bfs(i);		
		
		if(dfs(pr,pc,0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	
	}
	return 0;
}
