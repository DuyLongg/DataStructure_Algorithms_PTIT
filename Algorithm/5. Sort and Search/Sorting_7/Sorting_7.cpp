#include <bits/stdc++.h>
using namespace std;

int T,N,A[1000005],B[1000005];

int main (){
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 1 ; i <= N ; i++) {
			cin >> A[i];
			B[i] = A[i];
		}
		sort (B+1,B+N+1);
		int i = 1, j = N;
		while (B[i] == A[i]) i++;
		while (B[j] == A[j]) j--;
		if (i < j) cout << i << " " << j << endl;
		else cout << 0 << " " << 0 << endl;
	}
	return 0;
}
