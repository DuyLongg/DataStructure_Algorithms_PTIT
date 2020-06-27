#include <bits/stdc++.h>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int S,D; cin >> S >> D;
		if (9*D < S) {
			cout << -1 << endl;
			continue;
		}
		int kq[D]; 
		for (int i = D-1 ; i >= 0 ; i--){
			if (i > 0){
				for (int j = 9 ; j >= 0 ; j--){
					if (j < S) {
						kq[i] = j;
						S = S - j;
						break;
					}
				}
			} else kq[i] = S;
		}
		for (int i = 0 ; i < D ; i++) cout << kq[i];
		cout << endl;
	}
	return 0;
}
