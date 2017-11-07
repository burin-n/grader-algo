#include <bits/stdc++.h>
using namespace std;
int n,m,t[1010][1010];
string s1,s2,ans;


string print(int r,int c){
	if(r<=0 || c==0) return "";
	for(int i=c;i>0;i--){
		if(t[r][i-1] == t[r-1][i] && t[r-1][i-1] == t[r][i]-1){
			return print(r-1,i-1) + s1[r-1];		
		}
		else if(t[r][i-1] < t[r-1][i]){
			return print(r-1,i);		
		}

	}
	return print(r-1,c);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	cin >> s1 >> s2;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++)
			cin >> t[i][j];
	}
		cout << print(n,m) <<'\n';
	return 0;
}
