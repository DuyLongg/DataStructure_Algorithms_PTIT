#include <bits/stdc++.h>
using namespace std;

long long T,N,K,F[105][50005];
const int mod = 1e9+7;

long long Solve (){
	// F[N][K] la so day co N chu so co tong bang K
	// F[i][j] la so day co i chu so co tong bang j
	// F[i][j] = F[i-1][j-0] + F[i-1][j-1] + F[i-1][j-2] + .. F[i-1][j-9] . j > k
	// F[0][0] = 1; 
	memset(F,0,sizeof(F));
	for (int i = 1 ; i <= N ; i++){
		F[0][0] = 1;
		for (int j = 1 ; j <= K ; j++){
			for (int k = 0 ; k < 10 ; k++){
				if (k <= j) F[i][j] = (F[i][j] + F[i-1][j-k]) % mod;
				else break;
			}
		//	cout << "F[" << i << "][" << j << "] = " << F[i][j] << endl;
		}
	}
	return F[N][K];
}

int main (){
	cin >> T;
	while (T--){
		cin >> N >> K;
		cout << Solve() << endl;
	}
	return 0;
}
