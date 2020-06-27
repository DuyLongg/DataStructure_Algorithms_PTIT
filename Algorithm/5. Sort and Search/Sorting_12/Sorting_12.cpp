#include <bits/stdc++.h>
using namespace std;

long long T,N,M,A[1000005],B[1000005];

int main (){
	cin >> T;
	while (T--){
		cin >> N >> M;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		for (int i = 1 ; i <= M ; i++) cin >> B[i];
		sort (A+1,A+N+1); sort (B+1,B+N+1);
		cout << A[N]*B[1] << endl;
	}
	return 0;
}
