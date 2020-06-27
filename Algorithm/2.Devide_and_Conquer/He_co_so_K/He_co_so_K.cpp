#include <bits/stdc++.h>
using namespace std;

int main (){
	long long K; string A,B; 
	cin >> K >> A >> B;
	while (A.size() < B.size()) A = '0' + A;
	while (B.size() < A.size()) B = '0' + B;
	int nho = 0; string C = ""; char r;
	for (int i = B.size()-1 ; i >= 0 ; i--){
		int sum_tmp = (A[i]-'0') + (B[i]-'0') + nho;
		if (sum_tmp >= K) {
			r = (sum_tmp-K) + '0';
			C = r + C;
			nho = 1;
		} else {
			r = sum_tmp + '0';
			C = r + C;
			nho = 0;
		}
	}
	if (nho == 1) C = '1' + C;
	cout << C << endl;
	return 0;
}
