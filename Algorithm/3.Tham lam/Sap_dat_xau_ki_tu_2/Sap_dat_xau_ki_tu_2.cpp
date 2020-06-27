#include <bits/stdc++.h>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int D; cin >> D;
		string S; cin >> S;
		int tanso[125]; memset(tanso,0,sizeof(tanso));
		for (int i = 0 ; i < S.size() ; i++) tanso[S[i]-'A']++;
		int max = tanso[0];
		for (int i = 1 ; i < 125 ; i++)	if (tanso[i] > max) max = tanso[i];
		if (max <= (S.length()+1)/D) cout << 1;
		else cout << -1;	
		cout << endl;
	}
	return 0;
}

