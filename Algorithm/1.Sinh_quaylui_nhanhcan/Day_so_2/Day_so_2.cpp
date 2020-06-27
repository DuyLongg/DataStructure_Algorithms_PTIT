#include <iostream>
using namespace std;

void In (int A[],int N){
	cout << "[";
	for (int i = 0 ; i < N ; i++) {
		if (i < N-1) cout << A[i] << " ";
		else cout << A[i];
	}
	cout << "]";
}

void Try (int A[],int N){
	N--;
	for (int i = 0 ; i < N ; i++) A[i] = A[i] + A[i+1];
	int B[N];
	for (int i = 0 ; i < N ; i++) B[i] = A[i];
	if (N != 1) Try (B,N);
	In (A,N);
}
int main (){
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		int A[N],B[N];
		for (int i = 0 ; i < N ; i++) {
			cin >> A[i];
			B[i] = A[i];
		}
		if (N>1) Try (B,N);
		In (A,N);
		cout << endl;
	}
	return 0;
}
