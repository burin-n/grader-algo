#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
deque<ii> deq;
int n,w,a,s=0,ans=-2e9;

int main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> w;
	deq.push_front(ii(0,0));
	for(int i=1;i<=n;i++){
		cin >> a;	
		s+=a;
		while(!deq.empty() && i - deq.front().second > w) deq.pop_front();	
		ans = max(ans, s - deq.front().first);
		while(!deq.empty() && deq.back().first >= s ) deq.pop_back();
		deq.push_back(ii(s,i));
	}
	
	cout << ans << endl;
	return 0;
}
