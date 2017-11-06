#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int INF = 1e9;
int cost[11][10001], a[11];

void init(){
	for(int i=0;i<11;i++)
		for(int j=0;j<10001;j++)
			cost[i][j] = INF;

	cost[0][0] = 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	
	init();
	
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];

			
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=100 && j-k*k>=0;k++){
				int p = k*k;
				cost[i][j] = min(cost[i][j],cost[i-1][j-p] + (a[i]-k)*(a[i]-k));
			}	
		}
	}

	if(cost[n][m] == INF) cout << -1 << endl;
	else cout << cost[n][m] << endl;

	return 0;
}

