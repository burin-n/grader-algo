#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll len(int s){
	if(s == 0) return 3;
	return len(s-1)*2+s+3;
}

char solve(ll p,int k){
	if( k == 0 ){
		return p == 1 ? 'g' : 'a'; 
	}
	ll size = len(k-1);
	if( size >= p ) return solve(p,k-1);
	else if(size + k + 3 >= p){
		return p == size+1 ? 'g' : 'a';	
	}
	else return solve(p-size-k-3,k-1);
}


int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;	
	int level = 1;
	while(len(level) < n) level++;
	cout << solve(n,level) << endl;
	return 0;
}
