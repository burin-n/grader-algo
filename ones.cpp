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
#define INF 1e9
//----------------------------------------------------------
int primitive[12] = {0,1,2,3,4,5,6,6,5,4,3,2};
int p[11] = {0,1,11,111,1111,11111,111111,1111111,11111111,111111111,1111111111};

int dq(int n, int d){
//	cout << n <<":";
	if(n<=11) return primitive[n];
	else {
		//cout << d << ' ' << n << ' ' << n-p[d]*(n/p[d]) << ' ' << (p[d]*(n/p[d]+1))-n<< endl;

		int k = n/p[d];
		if( n%p[d] == 0) return d*k;

		int low = d*k + dq(n-p[d]*k, d-1);
		int high = d*(k+1) + dq(p[d]*(k+1)-n, d-1);
		return min(high,low);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int n;
	cin >> n;
	int d = 0;
	while(p[d] <= n) d++;	
	cout << dq(n,d) << endl;
	return 0;
}
