#include <bits/stdc++.h>
using namespace std;
int ans,r,c;
string a[1001];
int dp[1001][1001];

int main(){
	ios_base::sync_with_stdio(0);
	cin >> r >> c;
	for(int i=1;i<=r;i++){
		cin >> a[i];
		a[i] = " " + a[i];
	}
	
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(a[i][j] == '1'){
				if(a[i-1][j] && a[i][j-1] && a[i-1][j-1])
					dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
				else dp[i][j] = 1;
			}
			ans = max(ans,dp[i][j]);
		}
	}
	
	cout << ans << '\n';
	
}
