#include <bits/stdc++.h>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		int A[N+1];
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		int L[N+1][N+1]; 
		for (int i = 1 ; i <= N ; i++) L[i][i] = A[i];	
		int FOPT = 0;
		for (int i = 1 ; i <= N ; i++){
			for (int j = i+1 ; j <= N ; j++){
				L[i][j] = L[i][j-1] + A[j];
				if (L[i][j] > FOPT) FOPT = L[i][j];
			}
		}
		cout << FOPT << endl;
	}
	return 0;
}

