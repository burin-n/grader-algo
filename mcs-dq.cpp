#include <iostream>
using namespace std;
#define endl '\n'
#define INF 100000000
int a[100000+10];

int sumAcross(int l,int r){
	int mid = (l+r)/2;
	int sumleft = -INF;
	int sumright = -INF;	

	int temp = 0;
	for(int i=mid; i>=l ; i--){
		temp += a[i];
		sumleft = max(sumleft,temp);
	}

	temp = 0;
	for(int i=mid+1; i<=r; i++){
		temp+= a[i];
		sumright = max(sumright,temp);	
	}
	
	return sumleft + sumright;
}

int dq(int l,int r){

	if(l==r) return a[l];
	if(l>r) return -INF;

	int mid = (l+r)/2;
	int left = dq(l,mid);
	int right = dq(mid+1,r);
	int across = sumAcross(l,r);	
	
	return max(left,max(right,across));
}

int main(){
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	cout << dq(0,n-1) << endl;	

	return 0;
}
