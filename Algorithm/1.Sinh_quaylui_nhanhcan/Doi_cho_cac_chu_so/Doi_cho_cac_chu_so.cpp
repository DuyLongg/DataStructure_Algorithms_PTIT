#include <iostream>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int K; cin >> K;
		string S; cin >> S;
		for (int i = 0 ; i < S.size() && K > 0; i++){
			char max = S[i];
			int vt = i;
			for (int j = i+1 ; j < S.size() ; j++){
				if (S[j]>=max){
					max = S[j];
					vt = j;
				}
			}
			if (S[i]!=S[vt]) {
				swap(S[i],S[vt]);	
				K--;
			}
		}
		cout << S << endl;
	}
	return 0;
}
