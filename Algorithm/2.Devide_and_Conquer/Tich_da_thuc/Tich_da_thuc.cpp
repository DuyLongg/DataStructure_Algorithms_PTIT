#include <bits/stdc++.h>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int M,N; cin >> M >> N;
		int C[M],B[N],A[N+M-1]; 
		memset(A,0,sizeof(A));
		for (int i = 0 ; i < M ; i++) cin >> C[i];
		for (int i = 0 ; i < N ; i++) cin >> B[i];
		for (int i = 0 ; i < N ; i++) {
			for (int j = 0 ; j < M ; j++) A[i+j] = A[i+j] + B[i]*C[j];
		}
		for (int i = 0 ; i < N+M-1 ; i++) cout << A[i] << " ";
		cout << endl;
	}
	return 0;
}
