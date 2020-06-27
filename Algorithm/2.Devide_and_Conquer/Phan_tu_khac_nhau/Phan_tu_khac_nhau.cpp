#include <bits/stdc++.h>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		long long N; cin >> N;
		long long A[N+1],B[N];
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		for (int i = 1 ; i <= N-1 ; i++) cin >> B[i];
		int first = 1, last = N;
		int mid = (last+first)/2;
		while (first != last-1){
			if (A[mid]==B[mid]) first = mid;
			else last = mid;
			mid = (last+first)/2;
		}
		if (A[first] != B[first]) cout << first << endl;
		else cout << last << endl;
	}
	return 0;
}
