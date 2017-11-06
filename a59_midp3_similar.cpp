#include <bits/stdc++.h>
using namespace std;
string a,b;

bool solve(int al,int bl,int len){
	if(len == 1) return a[al] == b[bl];
	len/=2;
	return (solve(al,bl,len) && solve(al+len,bl+len,len)) ||
				 (solve(al,bl+len,len) && solve(al+len,bl,len));
}	

int main(){
	cin >> a >> b;
	cout <<(solve(0,0,b.length()) ? "YES" : "NO")<< endl;
	return 0;
}
