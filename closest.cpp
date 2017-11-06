#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

struct POINT{
	int x,y;
};
int n;
vector<POINT> p;

bool sortx(POINT a, POINT b){
	return a.x < b.x;
}

bool sorty(POINT a, POINT b){
	return a.y < b.y;
}

int dist(POINT a, POINT b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int lower_bound(int left, int right, int x, int delta){
	if(right<left) return INF;
	int mid = (left+right)/2;	
	if(abs(p[mid].x - x) > delta){
		if(mid+1 <= right && abs(p[mid+1].x - x)  <= delta) return mid+1;
		return lower_bound(mid+1,right,x,delta);
	}	
	else{
		if(mid-1 >= left && abs(p[mid-1].x - x) > delta) return mid; 
		return lower_bound(left,mid-1,x,delta);
	}
}

int upper_bound(int left, int right, int x, int delta){
	if(right<left) return -1;
	int mid = (left+right)/2;	
	if(abs(p[mid].x - x) > delta){
		if(mid-1 >= left && abs(p[mid-1].x - x) <= delta) return mid-1; 
		return upper_bound(left,mid-1,x,delta);
	}	
	else{
		if(mid+1 <= right && abs(p[mid+1].x - x)  > delta) return mid;
		return upper_bound(mid+1,right,x,delta);
	}
}

int min_across(int left,int right, int delta){
	sort(p.begin()+left,p.begin()+right+1,sorty);	
	int min_dist = INF;
	for(int i=left; i<right; i++){
		for(int j=i+1;j<=right && p[j].y - p[i].y <= delta; j++){
			min_dist = min(min_dist, dist(p[i],p[j]));
		}
	}
	return min_dist;
}

int closest(int left,int right){
	int mid = (left+right)/2;
	if(right<=left) return INF;	
	int min_left = closest(left,mid);
	int min_right = closest(mid+1,right);	
	int min_dist = min(min_left,min_right);	
	int mid_x = (p[mid].x + p[mid+1].x)/2.0;
	int i = min(lower_bound(left,mid,mid_x,min_dist),left);
	int j = max(upper_bound(mid+1,right,mid_x,min_dist),right);

	return min(min_left,min(min_right,min_across(i,j,min_dist)));		
}

int main(){
	ios_base::sync_with_stdio(0);
	POINT temp;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> temp.x >> temp.y;
		p.push_back(temp);
	}
	if( n == 1 ) cout << 0 <<endl;	
	else{
		sort(p.begin(),p.end(),sortx);
		cout << closest(0,n-1) << endl;
	}
	return 0;
}
