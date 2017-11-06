#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

template <typename T>
using pql = priority_queue<T, vector<T>, greater<T> >; 
template <typename T>
using pqm = priority_queue<T>;

#define mp make_pair
#define pb push_back
#define endl '\n'
//----------------------------------------------------------

int n;
vi a(100001,0);
vi temp(100001,0);

int dq(int l,int r){
	if(r<=l){
	 	return 0;
	}

	int mid = (l+r)/2;	
	int left_inversion = dq(l,mid);
	int right_inversion = dq(mid+1,r);	
	int left_index = l, right_index = mid+1;

	int cross = 0, index=left_index;

	while(left_index <= mid && right_index <= r){
		if(a[left_index] <= a[right_index]){
			temp[index++] = a[left_index++];
			cross += right_index-mid-1;	
		}
		else{
			temp[index++] = a[right_index++];
		}		
	}

	
	while(left_index <= mid){
	 	temp[index++] = a[left_index++];
		cross += right_index-mid-1;	
	}
	while(right_index <= r) temp[index++] = a[right_index++];

	for(int i=l;i<=r;i++)
		a[i] = temp[i];

	return left_inversion+right_inversion+cross;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	cout << dq(0,n-1) << endl;
	return 0;
}
