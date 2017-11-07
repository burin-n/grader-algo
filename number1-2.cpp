#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,l,r;

int len(int s){
	if(s <= 1) return 1;
	else return 2*len(s/2)+1;
}

ll travel(ll val,ll posL,ll posR){
	if(posR < l || posL > r) return 0 ;
	if(val <= 1 ){
		return val;
	}
	else{
		ll s = 0;
		ll mid = (posL + posR)/2;
		s += travel(val/2,posL,mid-1);
		s += travel(val%2,mid,mid);
		s += travel(val/2,mid+1,posR);
		return s;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> l >> r;	
	ll ans = travel(n,1,len(n));
	cout << ans << endl;	
	return 0;
}
