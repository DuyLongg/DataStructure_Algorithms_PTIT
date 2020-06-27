#include <iostream>
#include <math.h>
using namespace std;

void Sinh (int A[], int n){
	for (int i = n-1 ; i >= 0 ; i--){
		if (A[i] == 0){
			A[i] = 1;
			for (int j = i+1 ; j < n ; j++) A[j] = 0;
			break;
		}
	}
}

int main (){
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		int A[n] = {0};
		for (int i = 0 ; i < n ; i++) cout << 'A';
		cout << " ";
		int K = pow(2,n)-1;
		while (K--){
			Sinh (A,n);
			for (int i = 0 ; i < n ; i++){
				if (A[i] == 0) cout << 'A';
				else cout << 'B';
			} 
			cout << " ";
		}
		cout << endl;
	}
	return 0;
}
