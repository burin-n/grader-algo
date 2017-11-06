#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	int n,s,t,ans=-2e9;
	cin >> n;
	cin >> t;
	s = t;
	for(int i=1;i<n;i++){
		cin >> t;
		s = max(s+t,t);
		ans = max(ans,s);
	}
	cout << ans << '\n';
	return 0;
}
