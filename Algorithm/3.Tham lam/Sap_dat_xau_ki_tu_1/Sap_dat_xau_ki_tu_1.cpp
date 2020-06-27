#include <bits/stdc++.h>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int A[30]; memset(A,0,sizeof(A));
		string S; cin >> S;
		for (int i = 0 ; i < S.size() ; i++) A[S[i]-'a']++;
		int max = A[0];
		for (int i = 1 ; i < 30 ; i++) if (A[i] > max) max = A[i];
		if (max <= (S.length()+1)/2) cout << 1;
		else cout << -1;
		cout << endl;
	}
	return 0;
} 
