#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int p[10000+10],dp[10000+10];

int main(){
	ios_base::sync_with_stdio(0);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> p[i];
		dp[i] = 1e9;
	}

	dp[0] = 0;

	for(int i=1;i<=n;i++){
		int s = dp[max(0,i-k-1)];
		for(int j=max(0,i-k-1); j<i; j++)
			s = min(s,dp[j]);

		s += p[i];	
		for(int j=0;j<=k && i+j<=n;j++)
			dp[i+j] = min(dp[i+j],s);
//	for(int i=0;i<=n;i++)
//		cout << dp[i] << ' ';
//	cout<<endl;
	}

	cout << dp[n] << endl;
	return 0;
}
