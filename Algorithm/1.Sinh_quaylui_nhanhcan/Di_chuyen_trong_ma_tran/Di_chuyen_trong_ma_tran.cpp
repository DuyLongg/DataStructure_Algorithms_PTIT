#include <iostream>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int M,N; cin >> M >> N;
		int A[M+1][N+1];
		int dp[M+1][N+1];
		for (int i = 0 ; i < M ; i++){
			for (int j = 0 ; j < N ; j++){
				cin >> A[i][j];
				if (i==0 || j==0) dp[i][j] = 1;
			}
		}
		for (int i = 1 ; i < M ; i++){
			for (int j = 1 ; j < N ; j++){
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		cout << dp[M-1][N-1] << endl;
	}
	return 0;
}
