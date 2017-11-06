#include <bits/stdc++.h>
using namespace std;
int n,m, q[1001],w[1001], ds, dt, allw;

int solve(){
	int cw = 0, ccw = 0;
	for(int i = ds; i!=dt; i=(i+1)%m)
		cw += w[i];
	ccw = allw - cw;

	int s,t, wcw, wccw;
	int found_dt, found;
	found_dt = found = 0;
	wcw = wccw = 0;

	for(int i=0;i<m;i++){
		s = q[i];
		t = q[i+1];
		int j,k;	
		for(j=s ;j!=t ;j=(j+1)%m){
			cout << j << ' ';
			if( j == ds ) found++;
			if( j == dt ) found_dt = found++;	
			if(j == 0) wcw += w[m-1];
			else wcw += w[j];
		}
		if(found == 2){
			if(found_dt == 1) wcw -= cw;
			else wcw -= ccw;
		}
		found_dt = found = 0;
		cout << endl;
		for(j=s ;j!=t; j--){
				if(j<0) j = m-1;
				cout << j << ' ';
				if( j == ds ) found++;
				if( j == dt ) found_dt = found++;	
				k = min( j, (j+1)%m);

				wccw += w[j];
		}
		if(found == 2){
			if(found_dt == 1) wccw -= cw;
			else wccw -= ccw;
		}
		cout << endl;

	}
	return min(wcw,wccw);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=0;i<m;i++)
		cin >> q[i];
	q[m] = q[0];
	for(int i=0;i<m;i++){
		cin >> w[i];
		allw += w[i];
	}

	while(n--){
		cin >> ds >> dt;
		cout << solve() << endl;
	}

	return 0;
}

