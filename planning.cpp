#include <bits/stdc++.h>
using namespace std;

vector<bool> isFinish(1000,0);
vector<int> preReq[1000];

bool canPerform(int p){
	bool ans = true;
	for(int e : preReq[p])
		ans = ans & isFinish[e];
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n,m,t;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> m;
		for(int j=0;j<m;j++){
			cin >> t;
			preReq[i].push_back(t);
		}
	}	

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!isFinish[j] && canPerform(j)){
				isFinish[j]=1;
				cout << j << ' ';
			}
		}
	}

	return 0;
}
