#include <bits/stdc++.h>

using namespace std;
int q[1001][1001],dp[1001][1001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k,a,b,c,d;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> q[i][j];
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + q[i][j];
		}
	}

	for(int i=0;i<k;i++){
		cin >> a >> b >> c >> d;
		cout << dp[c+1][d+1] - dp[a][d+1] - dp[c+1][b] + dp[a][b] << endl;
	}	
	return 0;
}
