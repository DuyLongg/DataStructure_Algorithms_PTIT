#include <iostream>
#include <algorithm>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		int A[N];
		for (int i = 0 ; i < N ; i++) cin >> A[i];
		if (N%2){
			int mid = N/2;
			for (int i = 1 ; i <= N/2 ; i++){
				if (A[mid-i] > A[mid+i]) swap (A[mid-i],A[mid+i]);
			}
		} else {
			for (int i = 0 ; i < N/2 ; i++){
				if (A[i] > A[N-i-1]) swap (A[i],A[N-i-1]);
			}
		}
		int check = 0;
		for (int i = 0 ; i < N-1 ; i++){
			if (A[i] > A[i+1]) {
				check = 1;
				cout << "No";
				break;
			}
		}
		if (check == 0) cout << "Yes";
		cout << endl;
	}
	return 0;
}
