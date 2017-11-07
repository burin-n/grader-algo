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
//----------------------------------------------------------
int MAX_DEPTH = 0;

void fill(int left,int right,int ttop,int bottom,int space_y,int space_x,int depth){

	if(depth == MAX_DEPTH) return;

	int	center_y = (ttop + bottom)/2;
	int center_x = (left + right)/2;

	//cout << center_x << ' ' << center_y << ':' << space_x << ' ' << space_y << endl;

	int s_x[4] = {center_x-1,center_x,center_x-1,center_x};
	int s_y[4] = {center_y-1,center_y-1,center_y,center_y};
	int p_left[4] = {left,center_x,left,center_x};
	int p_right[4] = {center_x,right,center_x,right};
	int p_top[4] = {ttop,ttop,center_y,center_y};
	int p_bottom[4] = {center_y,center_y,bottom,bottom};

	int space_dir;	
	if( space_y < center_y ){
		if(space_x < center_x) space_dir = 0;
		else space_dir = 1;
	}
	else{
		if( space_x < center_x) space_dir = 2;
		else space_dir = 3;
	}
	
	s_x[space_dir] = space_x;
	s_y[space_dir] = space_y;
	
	cout << space_dir << ' ' << center_x-1 << ' ' << center_y-1 << endl;

	for(int i=0;i<4;i++)
		fill(p_left[i],p_right[i],p_top[i],p_bottom[i],s_y[i],s_x[i],depth+1);
}


int main(){
	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int L,X,Y;
	cin >> L >> X >> Y;
	MAX_DEPTH = log(L)/log(2);

	cout << (L*L-1)/3 << endl;
	fill(1,L,1,L,Y,X,0);

	return 0;
}
