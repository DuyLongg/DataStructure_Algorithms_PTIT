#include <iostream>
using namespace std;

int Binary_search (int A[], int K, int N){
	int first = 0, last = N-1;
	int mid;
	while (first <= last){
		mid = (first+last)/2;
		if (K < A[mid]) last = mid-1;
		else if (K > A[mid]) first = mid+1;
		else return mid+1;
	}
	return 0;
}

int main (){
	int T; cin >> T;
	while (T--){
		int N,K; 
		cin >> N >> K;
		int A[N];
		for (int i = 0 ; i < N ; i++) cin >> A[i];
		int kq = Binary_search(A,K,N);
		if (kq != 0) cout << kq << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
