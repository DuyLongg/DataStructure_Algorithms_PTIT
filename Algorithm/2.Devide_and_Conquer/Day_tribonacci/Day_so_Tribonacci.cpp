#include <iostream>
#include <vector>
#include <algorithm>
#define p 1000000000000007
using namespace std;

class matrix{
	public:
		long long a[3][3];
		matrix(){
			a[0][0] = a[0][2] = a[1][0] = a[1][1] = 0;
			a[0][1] = a[1][2] = a[2][0] = a[2][1] = a[2][2] = 1;			
		}
};

matrix mul (matrix a, matrix b){
	matrix c;
	for (int i = 0 ; i < 3 ; i++){
		for (int j = 0 ; j < 3 ; j++){
			c.a[i][j] = (a.a[i][0]*b.a[0][j] + a.a[i][1]*b.a[1][j] + a.a[i][2]*b.a[2][j]) % p;
		}
	}
	return c;
}

matrix power (matrix c, int N){
	if (N==1) return c;
	if (N%2) return mul(c, power(c,N-1));
	else{
		matrix r = power(c,N/2);;
		return mul(r,r);
	}
}

int main (){
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		if (N==1){
			cout << 1 << endl;
			continue;
		}
		matrix c;
		matrix b = power(c,N-1);
		long long Tn = b.a[0][0] + b.a[0][1]*2 + b.a[0][2]*3;
		long long Tn_plus_2 = b.a[2][0] + b.a[2][1]*2 + b.a[2][2]*3;
		cout << (Tn_plus_2 + Tn -2)/2 << endl;
	}
	return 0;
}
