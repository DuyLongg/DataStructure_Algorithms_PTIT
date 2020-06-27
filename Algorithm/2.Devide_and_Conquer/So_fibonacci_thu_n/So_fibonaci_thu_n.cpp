#include <iostream>
#define mod 1000000007
using namespace std;

class matrix{
	public:
		long long matran[2][2];
		matrix(){
			matran[0][0] = 0;
			matran[0][1] = 1;
			matran[1][0] = 1;
			matran[1][1] = 1;
		}
};

matrix matrix_X_matrix(matrix a, matrix b){
	matrix c;
	for (int i = 0 ; i <= 1 ; i++){
		for (int j = 0 ; j <= 1 ; j++){
			c.matran[i][j] = (a.matran[i][0]*b.matran[0][j] + a.matran[i][1]*b.matran[1][j]) % mod;
		}
	}
	return c;
}

matrix matrix_mu(matrix a, long long N){
	if (N==1) return a;
	if (N%2) return matrix_X_matrix(a, matrix_mu(a,N-1));
	else {
		matrix r = matrix_mu(a, N/2);
		return matrix_X_matrix(r,r);
	}
}

int main (){
	int T; cin >> T;
	matrix x;
	while (T--){
		long long N; cin >> N;
		matrix a = matrix_mu(x, N);
		cout << a.matran[0][1] << endl;
	}
	return 0;
}
