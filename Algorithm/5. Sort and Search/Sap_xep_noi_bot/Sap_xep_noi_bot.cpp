#include <iostream>
using namespace std;

int main (){
	int N; cin >> N;
	int A[N]; 
	int change = 0;
	for (int i = 0 ; i < N ; i++) cin >> A[i];
	for (int i = 1 ; i < N ; i++){
		for (int j = 0 ; j < N-1 ; j++){
			if (A[j] > A[j+1]) {
				swap (A[j],A[j+1]);
				change = 1;
			}
		}
		if (change==1) {
			cout << "Buoc " << i << ": ";
			for (int r = 0 ; r < N ; r++) cout << A[r] << " ";
			cout << endl;
			change = 0;
		} else break;
	}
	return 0;
}
