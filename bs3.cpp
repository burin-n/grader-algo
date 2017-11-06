#include <bits/stdc++.h>
using namespace std;

int n,m,a[100000+10];

int bsearch(int l,int r,int x){
	if(r<l) return -1;
	
	int mid = (l+r)/2;
	if(a[mid] > x ) {
		if(mid > 0 && a[mid-1] <= x ) return mid-1;
		else return bsearch(l,mid-1,x);
	}
	else{
		if(mid == n-1 || a[mid+1] > x) return mid;
		else return bsearch(mid+1,r,x);
	}

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<m;i++){
		cin >> x;
		cout << bsearch(0,n-1,x) << '\n';
	}
	return 0;
}
