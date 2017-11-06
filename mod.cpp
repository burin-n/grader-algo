#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod(ll x, ll n, ll k){
	if(n==1) return x%k;
	if((n&1)==0){
		//cout << "y" <<n << endl;
		ll t =  mod(x,n/2,k);
		return (t%k * t%k)%k;
	}		
	else{
		//cout << n << endl;
		ll t =  mod(x,n-1,k);
		return (t * x%k)%k;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll x,n,k;

	cin >> x >> n >> k;
		
	cout << mod(x,n,k) << endl;	

	return 0;
}
