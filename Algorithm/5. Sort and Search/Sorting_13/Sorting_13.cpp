#include <bits/stdc++.h>
using namespace std;

int T,N,M,A[1000005],B[1000005];

int main (){
	cin >> T;
	while (T--){
		cin >> N >> M;
		vector <int> mer(N+M);
		for (int i = 0 ; i < N ; i++) cin >> A[i];
		for (int i = 0 ; i < M ; i++) cin >> B[i];
		sort (A,A+N); sort (B,B+M);
		merge (A,A+N,B,B+M,mer.begin());
		for (int i = 0 ; i < N+M ; i++) cout << mer[i] << " ";
		cout << endl;
	}
	return 0;
}
