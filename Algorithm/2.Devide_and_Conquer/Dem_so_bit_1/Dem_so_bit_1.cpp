#include <iostream>
using namespace std;
#define ll long long 
ll N,L,R;

ll dodai (ll N){
	if (N==1) return 1;
	return dodai(N/2)*2+1;
}

ll demsobit1(ll N, ll first, ll last){
	if (last < L || first > R) return 0;
	if (first >= L && last <= R) return N;
	ll mid = (first+last)/2;
	if (mid >= L && mid <= R) return demsobit1(N/2,first,mid-1) + demsobit1(N/2,mid+1,last) + N%2;
	return demsobit1(N/2,first,mid-1) + demsobit1(N/2,mid+1,last);
}

int main (){
	int T; cin >> T;
	while (T--){
		cin >> N >> L >> R;
		ll len = dodai(N);
		cout << demsobit1(N,1,len) << endl;
	}
	return 0;
}
