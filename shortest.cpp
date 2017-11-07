#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
char mmap[101][101];
int n,m,imap[101][101];
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
bool visit[101][101];


bool isValid(int r,int c){
	if( r >=0 && r<n )
		if(c>=0 && c<m)
			if(mmap[r][c] == '.')
				return 1;
	
	return 0;
}

int bfs(){
	queue<ii> q;
	q.push(ii(0,0));
	if(mmap[0][0] == '.') imap[0][0] = 0;
	int r,c;
	while(!q.empty()){
		r = q.front().first;
		c = q.front().second;
		q.pop();
		visit[r][c] = 1;
		for(int i=0;i<4;i++){
			int nr = r+dr[i];
			int nc = c+dc[i];
			if(isValid(nr,nc)){
				if(!visit[nr][nc] && imap[nr][nc] > imap[r][c]+1){
					q.push(ii(nr,nc));
					imap[nr][nc] = imap[r][c]+1;
				}
			}
		}	
	}	
	return imap[n-1][m-1] == 1e9 ? -1 : imap[n-1][m-1];
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",mmap[i]);	

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			visit[i][j] = 0;
			imap[i][j] = 1e9;
		}


	printf("%d\n",bfs());

	return 0;
}

