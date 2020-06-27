#include <bits/stdc++.h>
using namespace std;

int T,N,K,A[1005];

int main (){
	cin >> T;
	while (T--){
		cin >> N >> K;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		sort (A+1,A+1+N);
		int i = N;
		while (K--) {
			cout << A[i] << " ";
			i--;
		}
		cout << endl;
	}
	return 0;
}
