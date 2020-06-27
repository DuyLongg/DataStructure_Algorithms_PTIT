#include <iostream>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int N,K; 
		cin >> N >> K;
		int A[K+1];
		for (int i = 1 ; i <= K ; i++) cin >> A[i];
		for (int i = K ; i >=1 ; i--) {
			if (A[i] != N-K+i) {
				A[i] = A[i]+1;
				for (int j = i+1 ; j <= K ; j++) A[j] = A[i]+j-i;
				break;	
			} 
			if (i==1) {
				for (int i = 1 ; i <= K ; i++) A[i] = i;
			}
		}
		for (int i = 1 ; i <= K ; i++) cout << A[i] << " ";
		cout << endl;
	}
	return 0;
}
