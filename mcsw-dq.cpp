#include <bits/stdc++.h>
using namespace std;
int n,w,a[200001];
int maxSum[200001];	

int sumAcross(int l, int r){
//	cout << l << "in" << r << endl;

	int mid = (l+r)/2;
	int left = max(l,mid-w+2);
	int right = min(r,mid+w-1);
	int ans = -2e9;
	maxSum[mid] = a[mid];

	for(int i=mid+1;i<=right;i++)
		maxSum[i] = maxSum[i-1] + a[i];			
	
	for(int i=mid+2;i<=right;i++)
		maxSum[i] = max(maxSum[i],maxSum[i-1]);
	
	int p,k=2,sum=0;	
	ans = maxSum[right];

	for(int i=mid-1; i>=left ; i--,k++){
		p = min(mid+w-k,r);
//		cout << i << ' ' << p <<',';
		sum += a[i];
		ans = max(ans,sum + maxSum[p]);
	}
	
//	cout <<endl;
	
	return ans;
}

int solve(int l,int r){
	int lm,rm,am;
	int mid = (l+r)/2;
	if(r<l) return -2e9;
	if(r==l) return a[l];
	lm = solve(l,mid);
	rm = solve(mid+1,r);
	am = sumAcross(l,r);	
	return max(lm,max(rm,am));	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> w;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	cout << solve(1,n) << endl;
	return 0;
}
