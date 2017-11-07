#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
int m[101];
const int INF = 1e9;

void init(){
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++)
			dp[i][j] = INF;
		dp[i][i] = 0;
	}

}

int solve(int i,int j){
	if(i == j) return dp[i][j]=0;
	if(dp[i][j] != INF) return dp[i][j];

	for(int k=i;k<j;k++)
		dp[i][j] = min(dp[i][j],solve(i,k) + solve(k+1,j) + m[i-1]*m[k]*m[j]);

	return dp[i][j];
}

int btmup(int n){
	for(int i=n;i>0;i--){
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++)
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+m[i-1]*m[k]*m[j]);
		}
	}
	return dp[1][n];
}

int main(){
	ios_base::sync_with_stdio(0);
	int n;

	cin >> n;
	for(int i=0;i<=n;i++)
		cin >> m[i];
	
	init();
	//cout << solve(1,n) << endl;	
	
	cout << btmup(n) << endl;

	return 0;
}
