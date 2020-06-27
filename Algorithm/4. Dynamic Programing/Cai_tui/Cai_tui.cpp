#include <bits/stdc++.h>
using namespace std;

long long T,N,V,A[1005],C[1005],L[1005][1005];

long long Solve(){
	int i,j;
	for (i = 0 ; i <= N ; i++) L[i][0] = 0;
	for (i = 0 ; i <= V ; i++) L[0][i] = 0;
	for (int i = 1 ; i <= N ; i++){
		for (j = 1 ; j <= V ; j++){
			L[i][j] = L[i-1][j];
			if (j >= A[i]) L[i][j] = max (L[i-1][j],L[i-1][j-A[i]] + C[i]);	
		}
	}
	return L[N][V];
}

int main (){
	cin >> T;
	while (T--){
		cin >> N >> V;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		for (int j = 1 ; j <= N ; j++) cin >> C[j];
		cout << Solve() << endl;
	}
	return 0;
}
