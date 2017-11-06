#include <bits/stdc++.h>
using namespace std;

struct Obj{
	double v,w,vpw;
}obj[100000+1];

int main(){
	int N;
	double W;

	cin >> W >> N;

	for(int i=0; i<N; i++)
		cin >> obj[i].v;
	
	for(int i=0;i<N ; i++){
		cin >> obj[i].w;
		obj[i].vpw = obj[i].v/obj[i].w;
	}

	sort(obj,obj+N,[] (Obj o1 , Obj o2){
		if(o1.vpw != o2.vpw) return  o1.vpw > o2.vpw;
		else return o1.w > o2.w;
	});
	
	double rw=W, sumv=0;
	for(int i=0;i<N && rw>0;i++){
		if(rw >= obj[i].w) sumv += obj[i].v;
		else sumv += obj[i].vpw * rw;
		rw -= obj[i].w;	
	}
	printf("%.4lf\n", sumv);
			
	return 0;
}
