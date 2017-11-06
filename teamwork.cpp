#include <bits/stdc++.h>
using namespace std;
priority_queue<int>pq,idle;

int main(){
	int n,m,temp,sum=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) idle.push(0);
	vector<int> a(m,0);
	for(int i=0;i<m;i++)
		scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	for(int e : a){
		temp = idle.top();	
		sum += -temp+e;
		idle.pop();
		idle.push(temp-e);	
	}
	printf("%.3lf\n",(double)sum/(double)m);
	return 0;
}
