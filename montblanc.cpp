#include <bits/stdc++.h>
using namespace std;
int c[100000+10];
int n,m,ans_day;

pair<bool,int> check(int k){
	int day_use = 1, max_reach=k;
	if( k < c[0] ) return make_pair(0,0);	
	for(int i=0;i<n;i++){
		if(c[i] > max_reach){
			day_use ++;
			max_reach = c[i-1]+k;
			if(day_use > m || max_reach < c[i]) return make_pair(0,day_use);
		}	
	}
	return make_pair(1,day_use);
}

pair<int,int> bsearch(int left, int right){
	if(right<left) return make_pair(-1,-1);
	int mid = (left+right)/2;
	pair<bool,int> ret = check(mid);
	pair<bool,int> ret_left = check(mid-1);

	if( ret.first ){
		if(!ret_left.first) return make_pair(mid,ret.second);
		else return bsearch(left,mid-1);
	}
	else return bsearch(mid+1,right);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> c[i];	


	pair<int,int> ans = bsearch(1,1e5);
	cout << ans.first << ' ' << ans.second << endl;
	return 0;
}

