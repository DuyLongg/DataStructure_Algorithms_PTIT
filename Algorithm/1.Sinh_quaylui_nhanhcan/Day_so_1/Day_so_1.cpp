#include <iostream>
using namespace std;

void In (int A[],int N){
	cout << "[";
	for (int i = 0 ; i < N ; i++) {
		if (i < N-1) cout << A[i] << " ";
		else cout << A[i];
	}
	cout << "]" << endl;
}

void Try (int A[],int N){
	for (int i = 0 ; i < N-1 ; i++) A[i] = A[i] + A[i+1];
	N--;
	In (A,N);
	if (N != 1) Try (A,N);
}
int main (){
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		int A[N];
		for (int i = 0 ; i < N ; i++) cin >> A[i];
		In (A,N);
		if (N>1) Try (A,N);
	}
	return 0;
}
