#include <bits/stdc++.h>
using namespace std;

int n,f[50];

int fibo(int k){
	if(f[k] > -1) return f[k];
	else return f[k] = fibo(k-1)+fibo(k-2);
}


int main(){
	cin >> n;
	for(int i=0;i<50;i++) f[i] = -1;
	f[0] = 0;
	f[1] = 1;
	cout << fibo(n) << endl;
	return 0;
}

