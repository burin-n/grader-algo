#include <bits/stdc++.h>
using namespace std;

struct C{
	int s,f;
};


int main(){
	int n;
	cin >> n;
	C event[n];
	for(int i=0;i<n;i++)
		cin >> event[i].s;
	for(int i=0;i<n;i++)
		cin >> event[i].f;

	sort(event,event+n,[](C e1, C e2){
			return e1.f < e2.f;
		});

	int ans=0, end=0;
	for(int i=0;i<n;i++){
		if( event[i].s >= end){
			ans++;
			end = event[i].f;
		}
	}
	cout << ans << '\n';

	return 0;
}
