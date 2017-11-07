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

//------------------------------------------------------------

vi a(100001,0);
int n,m,q;


int bsearch(int l,int r){
	if(r<l) return -1;
	int mid = (l+r)/2;

	if(a[mid] <= q ){
		if(mid == n-1 || a[mid+1] > q) return a[mid];
		else return bsearch(mid+1,r);
	}	
	else return bsearch(l,mid-1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];

	for(int i=0;i<m;i++){
		cin >> q;
		cout << bsearch(0,n-1) << endl;
	}


	return 0;
}
