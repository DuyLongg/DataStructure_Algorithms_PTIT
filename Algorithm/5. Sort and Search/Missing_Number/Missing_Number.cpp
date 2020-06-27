#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T,N,A[10000005];

int main (){
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 1 ; i < N ; i++) cin >> A[i];
		sort (A+1,A+N);
		for (int i = 1 ; i < N ; i++){
			if (i != A[i]) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
