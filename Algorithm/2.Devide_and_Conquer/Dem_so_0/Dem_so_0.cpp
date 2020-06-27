#include <bits/stdc++.h>
using namespace std;
// 0 0 0 0 0 0 0 1 1 1  1  1
// 1 2 3 4 5 6 7 8 9 10 11 12
int main (){
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		int A[N+1];
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		int first = 1, last = N;
		int mid = (last+first)/2;
		while (first != last-1) {
			if (A[mid] == 0) first = mid;
			else last = mid;
			mid = (last+first)/2;
		}
		if (!A[first] && A[last]) cout << first << endl;
		else if (A[first] == 1) cout << 0 << endl;
		else cout << N << endl; 
	}
	return 0;
}
