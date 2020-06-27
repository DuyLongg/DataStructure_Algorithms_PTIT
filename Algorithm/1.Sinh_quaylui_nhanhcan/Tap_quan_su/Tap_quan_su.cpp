#include <iostream>
using namespace std;

int N,K;

int Sinh (int B[]){
	for (int i = K ; i >= 1 ; i--){
		if (B[i] != N-K+i){
			B[i] = B[i]+1;
			for (int j = i+1 ; j <= K ; j++) B[j] = B[i]+j-i;
			return 1;
		}
	}
	return 0;
}

int main (){
	int T; cin >> T;
	while (T--){
		cin >> N >> K;
		int A[K+1],B[K+1];
		int dem = 0;
		for (int i = 1 ; i <= K ; i++) {
			cin >> A[i];
			B[i] = A[i];
		}	
		if(Sinh (B)==1){
			for (int i = 1 ; i <= K ; i++){
				for (int j = 1 ; j <= K ; j++){
					if (B[i]==A[j]) dem++;
				}
			}
			cout << K-dem << endl;	
		} else cout << K << endl;
	}
	return 0;
}
