#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T,N,X,A[1000005],mid;

int BS (ll fi, ll la){
	while (fi <= la){
		mid = (la+fi)/2;
		if (X < A[mid])  la = mid-1;
		else if (X > A[mid])  fi = mid+1;
		else return 1;
	}
	return -1;
}

int main (){
	cin >> T;
	while (T--){
		cin >> N >> X;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		cout << BS (1,N) << endl;
	}
	return 0;
}
