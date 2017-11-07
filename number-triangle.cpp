#include <bits/stdc++.h>
using namespace std;

int tb[101][101];
int dp[101][101];

int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			cin >> tb[i][j];
	
	dp[0][0] = tb[0][0];
	for(int i=0;i<n-1;i++){
		for(int j=0;j<=i;j++){
			dp[i+1][j] = max(dp[i+1][j],dp[i][j] + tb[i+1][j]);
			dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + tb[i+1][j+1]);
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++)
		ans = max(ans,dp[n-1][i]);	
	cout << ans << endl;
	return 0;
}


