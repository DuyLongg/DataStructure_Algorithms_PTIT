#include <bits/stdc++.h>
using namespace std;

long long T,N,A[1000005],F[1000005];

long long Solve (){
	// F[N] la tong lon nhat cua day con khong ke nhau chua A[N]
	// F[i] la tong lon nhat cua day con khong ke nhau chua A[i]
	memset (F,0,sizeof(F));
	F[1] = A[1]; F[2] = A[2];
	long long maxL = A[1];
	for (int i = 3 ; i <= N ; i++){
		F[i] = max (F[i-2],F[i-3]) + A[i];
		if (F[i] > maxL) maxL = F[i];
	}
	return maxL;
}

int main (){
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		cout << Solve() << endl;
	}
	return 0;
}
