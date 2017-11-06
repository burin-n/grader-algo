#include <bits/stdc++.h>
using namespace std;
int n,a[100001],s[4];
int mem[4][4];

int main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		s[a[i]]++;
	}
	int group = 1, c=0, ans=0;
	for(int i=0;i<n;i++){
		if(c>=s[group]) c=0,group++;
		if(group != a[i]) mem[group][a[i]]++;		
		c++;
	}

	for(int i=1;i<=3;i++){
		for(int j=i+1;j<=3;j++){
			if(mem[i][j] > 0 && mem[j][i] > 0){
				int t = min(mem[i][j],mem[j][i]);
				mem[i][j] -= t;
				mem[j][i] -= t;
				ans+=t;
			}
		}
	}
//	for(int i=1;i<=3;i++){
//		for(int j=1;j<=3;j++){
//			cout << mem[i][j] << ' ';
//		}
//		cout << endl;
//	}
	//cout << endl;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if( i == j ) continue;
			for(int k=1;k<=3;k++){
				if(k == i) continue;
				//cout << i << ',' << j << ' ' << k << ',' << i << endl;
				if(mem[k][i] && mem[i][j]){
					int t = min(mem[k][i],mem[i][j]);
					mem[i][j] -= t;
					mem[k][i] -= t;
					if(k!=j) mem[k][j] += t;
					ans+=t;
//					for(int i=1;i<=3;i++){
//						for(int j=1;j<=3;j++){
//							cout << mem[i][j] << ' ';
//						}
//						cout << endl;
//					}
//					cout << endl;
				}
			}
		}
	}
//	for(int i=1;i<=3;i++){
//		for(int j=1;j<=3;j++){
//			cout << mem[i][j] << ' ';
//		}
//		cout << endl;
//	}

	cout << ans << endl;	
	
	return 0;
}
