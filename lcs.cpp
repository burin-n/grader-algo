#include <bits/stdc++.h>
using namespace std;

int dp[501][501];

int main(){
	ios_base::sync_with_stdio(0);
	string s1,s2;
	cin >> s1 >> s2;
	int n = s1.length();
	int m = s2.length();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
			}
		}
	}	
	cout << dp[n][m] << endl;
	return 0;
}
