#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n,m,c;
	const int INF = 1e9;
	cin >> n >> m;
	vector<int> dp(10001,INF);
	dp[0] = 0;
		
	for(int i=0;i<n;i++){
		cin >> c;
		for(int j=c;j<=m;j++){
			dp[j] = min(dp[j],dp[j-c]+1);	
		}

	}
	cout << dp[m] << endl;
	return 0;
}
