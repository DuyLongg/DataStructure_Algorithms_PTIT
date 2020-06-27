#include <bits/stdc++.h>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int N,X; cin >> N >> X;
		long long A[N+1];
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		if (X < A[1]) {
			cout << -1 << endl;
			continue;
		}
		if (X > A[N]) {
			cout << A[N] << endl;
			continue;
		}
		int first = 1,last = N;
		int mid = (last+first)/2;
		while (first != last){
			if(A[mid] > X) last = mid-1;
			else first = mid+1;
			mid = (last+first)/2;
		}
		if (A[mid] <= X) cout << mid << endl;
		else cout << mid-1 << endl;
	}
	return 0;
}
