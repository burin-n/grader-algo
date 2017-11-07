#include <bits/stdc++.h>
using namespace std;

int n,a[600000],tempx,tempy,c;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];

	for(int k=0;k<log2(n);k++){
		c = 0;
		int shift = 1 << k;

		for(int i=0;i<n;i++){
			if(c == shift){
				i += shift-1;
				c=0;
				continue;
			}
//			cout << i << ' ' << i+shift  << ':'<< c << ' ' << k <<endl;
			tempx = a[i];
			tempy = a[i+shift];	
			a[i] = tempx + tempy;
			a[i+shift] = tempx - tempy;
			c++;
		}
	}

	for(int i=0;i<n;i++)
		cout << a[i] <<' ';
	return 0;
}
