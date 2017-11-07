#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll len(int p){
	if(p<=1) return 1;
	else return len(p/2)*2+1;
}

int isOne(int p, int n){
	//cout << p << ' ' << n  << endl;
	if( p <= 1 ) return p;

	ll sizec = len(n/2);
	if(sizec >= p) return isOne(p,n/2);			
	else if(sizec + 1 == p) return n%2;
	else return isOne(p - sizec - 1,n/2);
}

int main(){
	int n,l,r;
	cin >> n >> l >> r;
	ll ans=0;
	while(l<=r){
		ll t =  isOne(l++,n) ;
	//	cout << t << endl << endl;
		ans += t;
	}		
	cout << ans << endl;

	return 0;
}

