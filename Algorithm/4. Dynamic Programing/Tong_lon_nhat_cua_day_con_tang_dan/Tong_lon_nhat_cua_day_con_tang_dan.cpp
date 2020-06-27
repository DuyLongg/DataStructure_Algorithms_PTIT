#include <bits/stdc++.h>
using namespace std;

int T,N,A[1005],L[1005]; // L[i] la tong lon nhat cua day con tang dan va co chua A[i] . 

int Solve (){
	int maxL = A[1];
	L[0] = 0; L[1] = A[1];
	for (int i = 2 ; i <= N ; i++){
		L[i] = A[i];
		for (int j = 1 ; j < i ; j++)
			if (A[j] < A[i]) L[i] = max (L[i],L[j]+A[i]);
		if (L[i] > maxL) maxL = L[i];
	}
	return maxL;
}

int main (){
	cin >> T;
	while (T--){
		memset (L,0,sizeof(L));
		cin >> N;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		cout << Solve() << endl;
	}
	return 0;
}
