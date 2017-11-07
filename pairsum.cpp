#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n';

int a[1000000+10];

bool bsearch(int l,int r, int x){
	int mid = (l+r)/2;
	//cout << l << ' ' << r << endl;
	if(l>r) return false;		
	else if(a[mid] == x) return true;	
	else if(a[mid] > x) return bsearch(l,mid-1,x);
	else return bsearch(mid+1,r,x);
}

int main(){
//	cin.tie(0);
//	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];		

	sort(a,a+n);

	int query;
	bool isWin = false;

	for(int i=0;i<m;i++){
		cin >> query;
		isWin = false;
		for(int j=0;j<n;j++){
			//cout << query-a[j] << ' ' << j <<endl;
			if(query-a[i] > a[i])
				isWin = bsearch(j+1,n-1,query-a[j]);
			else
				isWin = bsearch(0,j-1,query-a[j]);
			if(isWin){
				cout << "YES" << endl;
				break;
			}
		}
		if(!isWin)cout << "NO" <<endl;
	}

	return 0;
}
