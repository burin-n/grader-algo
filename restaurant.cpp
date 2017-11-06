#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

template <typename T>
using pql = priority_queue<T, vector<T>, greater<T> >; 
template <typename T>
using pqm = priority_queue<T>;

#define mp make_pair
#define pb push_back
#define endl '\n'

//----------------------------------------------------------

int N,A,t[1001];
ll c;
const ll MAXT = 1e15;	

ll bsearch(ll left, ll right){
	if(right<left) return 0;
	ll sum = N;
	ll mid = (left+right)/2;
	ll checkleft = N;
	for(int i=0;i<N;i++){
		sum += mid/t[i];
		checkleft += (mid-1)/t[i];
	}	
	if(sum >= c){
		if(checkleft < c) return mid;
		else return bsearch(left,mid-1);
	}	
	else return bsearch(mid+1LL,right);
}


int main(){
	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);

	cin >> N >> A ;
	for(int i=0;i<N;i++)
		cin >> t[i];
	
	for(int i=0;i<A;i++){
		cin >> c;
		cout << bsearch(0,MAXT) << endl;
	}

	return 0;
}
