#include <iostream>
using namespace std;

bool Sinh (int A[], int N, int K){
	for (int i = K ; i > 0 ; i--){
		if (A[i] != N-K+i){
			A[i] = A[i] + 1;
			for (int j = i+1 ; j <= K ; j++) A[j] = A[i]+j-i;
			return true;
		}
	}
	return false;
}

int main (){
	int T; cin >> T;
	while (T--){
		int N,K; cin >> N >> K;
		int A[K+1]; 
		for (int i = 1 ; i <= K ; i++) {
			A[i] = i;
			cout << i;
		}
		cout << " ";
		while (Sinh (A,N,K)) {
			for (int i = 1 ; i <= K ; i++) cout << A[i];
			cout << " ";
		}
		cout << endl;
	}
	return 0;
}
