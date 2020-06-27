#include <bits/stdc++.h>
using namespace std;

int T,N,A[1005];

int main (){
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		sort (A+1,A+N+1);
		for (int i = 1 ; i <= N/2 ; i++)
			cout << A[N-i+1] << " " << A[i] << " ";
		if (N%2) cout << A[(N+1)/2];
		cout << endl;
	}
	return 0;
}
