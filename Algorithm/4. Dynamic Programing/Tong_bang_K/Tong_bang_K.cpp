#include <bits/stdc++.h>
using namespace std;

long long T,N,K,A[1005],F[100005];
const int mod = 1e9+7;
// F[K] la so cach lay tong phan tu de bang K
// F[j] la so cach lay tong phan tu de bang j
// F[j] = F[j-A[1]] + F[j-A[2]] + ... . Chu y: j >= A[i]
// F[0] = 1;
long long Solve (){
	memset (F,0,sizeof(F));
	F[0] = 1;
	for (int j = A[1] ; j <= K ; j++){
		for (int i = 1 ; i <= N ; i++){
			if (j >= A[i] && A[i] != A[i-1]) F[j] = (F[j] + F[j-A[i]]) % mod;
			//cout << "F[" << j << "] = " << F[j] << endl;	
		}
	}
	return F[K];
}

int main (){
	cin >> T;
	while (T--){
		memset(A,0,sizeof(A));
		cin >> N >> K;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		sort(A+1,A+N+1);
		cout << Solve() << endl;
	}
	return 0;
}
