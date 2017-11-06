#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a(1001,0),dp(1001,1e9);


int main(){
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];

	for(int i=1;i<=n;i++){
		auto p = lower_bound(dp.begin()+1,dp.end(), a[i]);	
		//cout <<a[i]<<' '<< p-dp.begin() << endl;
		dp[p-dp.begin()] = min(dp[p-dp.begin()],a[i]);
	}
	int ans =0;
	for(int i=1;i<=n;i++)
		if(dp[i] < 1e9) ans = i;
	cout << ans << endl;
	return 0;
}
