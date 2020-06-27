#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T,N,A[10000005];

int main (){
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		sort (A+1,A+N+1);
		for (int i = 2 ; i <= N ; i++){
			if (A[i] != A[1]) {
				cout << A[1] << " " << A[i] << endl;
				break;
			}
			if (i==N) cout << -1 << endl;
		}
	}
	return 0;
}
