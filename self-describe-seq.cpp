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

//---------------------------------------------------------
vii num;
// first : first index of number
// second : number of instance

int bsearch(int l,int r,int q){
	int mid = (l+r)/2;
	int firstIndex = num[mid].first;
	int lastIndex = num[mid].first + num[mid].second-1;

	if(firstIndex <= q && q <= lastIndex) return mid;
	else if( lastIndex < q ) return bsearch(mid+1,r,q);
	else return bsearch(l,mid-1,q);

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	num.pb(ii(0,0));
	num.pb(ii(1,1));
	num.pb(ii(2,2));
	
	int n,x;
	cin >> n;
	int index = 2, p=2, c=1;

	while(index <= 2e9){
		index += num.back().second;
		c++;

		num.pb( ii(index,p));	

		if( c == num[p].second ){
			c=0;
			p++;
		}
	}


//	for(int i=0;i<20;i++)
//		cout << i<< ": "<< num[i].first << ' ' << num[i].second << endl;
	for(int i=0;i<n;i++){
		cin >> x;
		cout <<	bsearch(0,num.size()-1,x) << endl;	
	}
	

	return 0;
