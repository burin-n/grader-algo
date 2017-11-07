#include <bits/stdc++.h>
using namespace std;

struct Obj{
	int own_set;
	vector<int> upper_set;
}stu[5000];

int N,P,w,l;

int own_set(int k){
	if( stu[k].own_set == k ) return k;
	else return own_set(stu[k].own_set);
}

int find_rank(int s,int r){
	int os = own_set(s);
	if( stu[os].upper_set.empty() ) return r;
	int minrank = 1e9;
	for(int u : stu[os].upper_set)
		minrank = min(minrank, find_rank( stu[os].upper_set, r+1 ));	
	return minrank;
}

bool is_lose_upper_win(int win,int lose){
	if( win == lose ) return 1;
	if( stu[win].upper_set.empty() ) return 0;
	int ans = false;
	for(int u : stu[win].upper_set)
		ans = ans | is_lose_upper_win(own_set(stu[win].upper_set),lose);
	return ans;
}

bool is_win_upper_lose(int win,int lose){
	if( win == lose ) return 1;
  if( stu[lose].upper_set.empty() ) return 0;
	int ans = false;
	for(int u : stu[lose].upper_set)
		ans = ans | is_win_upper_lose( win, own_set(stu[lose].upper_set );	
	return ans;
}

void Union(int a,int b){
	int oa = own_set(a);
	int ob = own_set(b);
	if(is_win_upper_lose( oa, ob )) return;
	if(!is_lose_upper_win( oa, ob )) stu[ob].upper_set.push_back(oa);
	else{
		while( 1 ){
			stu[oa].own_set = ob;
			int upper = stu[oa].upper_set;
			stu[oa].upper_set = stu[ob].upper_set;
			if( oa == ob ) break;
			oa = own_set(upper);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);

	for(int i=0;i<5000;i++)
		stu[i].own_set = i;

	cin >> N >> P;

	while(P--){
		cin >> w >> l;
		Union(w,l);
	}

	vector<int> ans(5001,0);
	for(int i=0;i<N;i++){
		ans[find_rank(i,1)]++;
	}
	int index=1, c = 0;
	while( c < N ){
		c += ans[index];
		cout << ans[index++] << ' ';
	}
	cout << '\n';	
	
	return 0;
}
