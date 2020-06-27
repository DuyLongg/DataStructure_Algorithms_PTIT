#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T,N,X,A[10000005],vt,mid;

int BS (ll fi, ll la){
	while (fi <= la){
		mid = (fi+la)/2;
		if (X < A[mid]) la = mid-1;
		else if (X > A[mid]) fi = mid+1;
		else return mid;
	}
	return 0;
}

int main (){
	cin >> T;
	while (T--){
		cin >> N >> X;	
		for (int i = 1 ; i <= N ; i++) {
			cin >> A[i];
			if (A[i] <= A[i-1]) vt = i;
		}
		ll bs1 = BS (1,vt-1);
		ll bs2 = BS (vt,N);
		if (bs1) cout << bs1 << endl;
		else cout << bs2 << endl;
	}
	return 0;
}
