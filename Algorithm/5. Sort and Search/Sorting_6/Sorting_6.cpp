#include <bits/stdc++.h>
using namespace std;

int T,N,A[1000005];

int main (){
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		sort (A+1,A+N+1);
		for (int i = 1 ; i <= N ; i++) cout << A[i] << " ";
		cout << endl;
	}
	return 0;
}
