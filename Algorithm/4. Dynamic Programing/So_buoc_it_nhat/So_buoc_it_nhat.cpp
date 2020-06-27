#include <bits/stdc++.h>
using namespace std;

int T,N,A[1005],F[1005];

int Solve (){
	memset (F,0,sizeof(F));
	int maxL = 1;
	for (int i = 1; i <= N ; i++){
		F[i] = 1;	
		for (int j = 1 ; j < i ; j++){
			if (A[j] <= A[i]) F[i] = max (F[i],F[j]+1);
		}
		if (F[i] > maxL) maxL = F[i];
	}
	return N-maxL;
}

int main (){
	cin >> T;
	while(T--){
		cin >> N;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];	
		cout << Solve() << endl;
	}
	return 0;
}
