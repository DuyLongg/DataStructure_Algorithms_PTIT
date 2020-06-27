#include <bits/stdc++.h>
using namespace std;

// C[n][r] = C[n-1][r] + C[n-1][r-1]

const int mod = 1e9+7;
long long T,C[1005][1005];

int main (){
	cin >> T;
	while (T--){
		int N,K;
		memset(C,0,sizeof(C));
		cin >> N >> K;
		for (int i = 0 ; i <= N ; i++) C[i][0] = 1;
		for (int i = 1 ; i <= N ; i++){
			for (int j = 1 ; j <= i ; j++){
				C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
			}
		}
		cout << C[N][K] << endl;
	}
	return 0;
}
