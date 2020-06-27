#include <bits/stdc++.h>
using namespace std;

long long T,N,K,A[1005],L[1005][55];

int main (){
	cin >> T;
	while (T--){
		memset(L,0,sizeof(L));
		cin >> N >> K;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		for (int j = 0 ; j <= K-1 ; j++) L[1][j] = (A[1] % K == j) ? 1 : 0;
		for (int i = 2 ; i <= N ; i++){
			for (int j = 0 ; j <= K-1 ; j++){
				int r = A[i] % K;
				L[i][j] = L[i-1][j];
				if (j==r && L[i][j] <= L[i-1][0]) L[i][j] = L[i-1][0] + 1;
				else if (L[i-1][(j-r+K)%K] > 0 && L[i][j] <= L[i-1][(j-r+K)%K])	L[i][j] = L[i-1][(j-r+K) % K] + 1;
			}
		}
		cout << L[N][0] << endl;
	}
	return 0;
}

