#include <iostream>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		string T,S;
		cin >> T >> S;
		S.insert(0, "0");
		int T_size = T.size();
		int S_size = S.size();
		int pi[S_size];
		
		int K = 0;
		pi[1] = 0;
		for (int i = 2 ; i < S_size ; i++){
			while (K > 0 && S[K+1] != S[i]) K = pi[K];
			if (S[K+1] == S[i]) K++;
			pi[i] = K;
		} 
		
		int R = 0;
		for (int i = 0 ; i < T_size ; i++){
			while (R > 0 && S[R+1] != T[i]) R = pi[R];
			if (S[R+1] == T[i]) R++;
			if (R == S_size-1) {
				cout << "YES" << endl;
				break;
			}
		}
		if (R < S_size-1) cout << "NO" << endl;
	}
	return 0;
}
