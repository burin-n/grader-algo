#include <bits/stdc++.h>
using namespace std;

int c[31][31];
int C(int n,int k){
	if(c[n][k] > 0) return c[n][k];
	else if(n == k || k == 0) return c[n][k] = 1;
	else return c[n][k] = C(n-1,k-1)+C(n-1,k);
}

int main(){
	int n,k;
	cin >> n >> k;
	cout << C(n,k) << endl;
	return 0;
}
