#include <iostream>
using namespace std;

int N,K;

class matrix {
	public:
		long long a[10][10];
};

matrix Matrix_base(int N){
	matrix b;
	for (int i = 0 ; i < N ; i++){
		for (int j = 0 ; j < N ; j++){
			cin >> b.a[i][j];
		}
	}
	return b;
}

matrix mul_matrix (matrix a, matrix b){
	matrix c;
	for (int i = 0 ; i < N ; i++){
		for (int j = 0 ; j < N ; j++){
			c.a[i][j] = 0;
			for (int p = 0 ; p < N ; p++){
				c.a[i][j] = (c.a[i][j] + a.a[i][p]*b.a[p][j]) % 1000000007;
			}
		}
	}
	return c;
}

matrix Matrix_pow(matrix b, int K){
	if (K==1) return b;
	if (K%2) return mul_matrix(b, Matrix_pow(b,K-1));
	else {
		matrix r = Matrix_pow(b,K/2);
		return mul_matrix(r,r);
	}
}

void Show (matrix c){
	for (int i = 0 ; i < N ; i++){
		for (int j = 0 ; j < N ; j++){
			cout << c.a[i][j] << " ";
		}
		cout << endl;
	}
}

int main (){
	int T; cin >> T;
	while (T--){
		cin >> N >> K;
		matrix b = Matrix_base(N);
		matrix c = Matrix_pow(b,K);
		Show (c);
	}
	return 0;
}
