#include <iostream>
using namespace std;

int main (){
	int N; cin >> N;
	int A[N];
	for (int i = 0 ; i < N ; i++) cin >> A[i];
	for (int i = 0 ; i < N-1 ; i++){
		for (int j = i+1 ; j < N ; j++){
			if (A[j] < A[i]) swap (A[i],A[j]);
		}
		cout << "Buoc " << i+1 << ": ";
		for (int r = 0 ; r < N ; r++) cout << A[r] << " ";
		cout << endl;
	}
	return 0;
}
