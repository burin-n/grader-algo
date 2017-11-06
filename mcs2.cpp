#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;

template <typename T>
using pql = priority_queue<T, vector<T>, greater<T> >; 
template <typename T>
using pqm = priority_queue<T>;

#define mp make_pair
#define pb push_back
#define endl '\n'
#define INF 1e9
//----------------------------------------------------------

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	ll a[100000+10];
	cin>> n;
	for(int i=0;i<n;i++)
		cin >> a[i];

	ll omax = -INF,sum = 0;
	for(int i=0;i<n;i++){
		sum = max(sum+a[i],a[i]);	
		omax = max(omax,sum);
	}
	
	ll imax = INF, all =0;
	sum=0;
	for(int i=0;i<n;i++){
		sum = min(sum+a[i],a[i]);	
		imax = min(imax,sum);
		all += a[i];
	}
	if( all == imax ) imax = omax;
	else imax = all-imax;
	
	cout << max(omax,imax) << endl;

	return 0;
}
