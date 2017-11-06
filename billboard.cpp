#include <bits/stdc++.h>
using namespace std;
int n,a[10000+1],dp[10000+1];

int main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];

	dp[0]=0;
	dp[1]=a[1];
	for(int i=2;i<=n;i++){
		dp[i] = max(dp[i-1],dp[i-2]+a[i]);
	}
	cout << max(dp[n],dp[n-1]) << endl;
	return 0;
}

