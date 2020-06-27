#include <bits/stdc++.h>
using namespace std;

int main (){
	int N; cin >> N;
	int A[N];
	for (int i = 0 ; i < N ; i++) cin >> A[i];
	cout << "Buoc 0: " << A[0] << endl;
	for (int i = 1 ; i < N ; i++){
		int key = A[i];
		for (int j = i-1 ; j >= 0 ; j--){
			if (key >= A[j]) {
				A[j+1] = key;
				break;
			} else A[j+1] = A[j];
			if (j == 0)	A[0] = key;
		}
		cout << "Buoc " << i << ": ";
		for (int n = 0 ; n <= i ; n++) cout << A[n] << " ";
		cout << endl;
	}
	return 0;
}
