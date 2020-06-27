#include <bits/stdc++.h>
#define ll long long
#define total_pair tp
using namespace std;
// code tham khao : https://www.geeksforgeeks.org/find-number-pairs-xy-yx/
ll T,N,M,X[100005],Y[100005];

ll count (ll X, ll Excep[]){
	if (X==0) return 0;
	if (X==1) return Excep[0];
	ll *idx = upper_bound(Y+1,Y+M+1,X);
	ll ans = (Y+M+1) - idx;
	ans = ans + Excep[0] + Excep[1];
	if (X==2) ans = ans - (Excep[3] + Excep[4]);
	if (X==3) ans = ans + Excep[2];
	return ans;
}

ll count_pair (){
	ll Excep[5] = {0};
	for (int i = 1 ; i <= M ; i++) 
		if (Y[i] < 5) Excep[Y[i]] ++;
	sort (Y+1,Y+M+1);
	ll tp = 0;
	for (int i = 1 ; i <= N ; i++) tp = tp + count (X[i],Excep);
	return tp;
}

int main (){
	cin >> T;
	while (T--){
		cin >> N >> M;
		for (int i = 1 ; i <= N ; i++) cin >> X[i];
		for (int i = 1 ; i <= M ; i++) cin >> Y[i];
		cout << count_pair () << endl;
	}
	return 0;
}
