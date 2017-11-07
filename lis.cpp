#include <bits/stdc++.h>
using namespace std;
int n,a[1001],dp[1001];

int main(){
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++){
		dp[i] = 1;
		for(int j=0;j<i;j++){
			if(a[i] > a[j]) dp[i] = max(dp[i],dp[j]+1);
		}
	}
	int ans =0;
	for(int i=1;i<=n;i++)
		ans = max(ans,dp[i]);
	cout << ans << endl;
	return 0;
}
