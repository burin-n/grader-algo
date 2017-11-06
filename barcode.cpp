#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int dp[31][31],n,m,k;

void init(){
	for(int i=0;i<31;i++)
		for(int j=0;j<31;j++)
			dp[i][j] = -1;
}

int solve(int size,int sep){
	if(dp[size][sep] > -1 ) return dp[size][sep];
	if(sep == 0){
		if(size<=m) return dp[size][sep] = 1;
		else return dp[size][sep] = 0;
	}			
	dp[size][sep] = 0;
	for(int i=1;i<=m && i<size;i++){
		dp[size][sep] += solve(size-i,sep-1);
	}
	return dp[size][sep];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> k;
	init();
	cout << solve(n,k) << endl;			
	return 0;
}

