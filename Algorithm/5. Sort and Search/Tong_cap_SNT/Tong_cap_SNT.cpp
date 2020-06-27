#include <bits/stdc++.h>
using namespace std;

int T,N,Ethoni[1000100];

void Sang (){
	Ethoni[0] = Ethoni[1] = 1;
	for (int i = 2 ; i < 1000100 ; i++){
		if (!Ethoni[i]){
			for (int j = 2 ; i*j < 1000100 ; j++){
				Ethoni[i*j] = 1;
			}
		}
	}
}

int main (){
	cin >> T;
	memset (Ethoni,0,sizeof(Ethoni));
	Sang();
	while (T--){
		int check = 0;
		cin >> N;
		for (int i = 2 ; i <= N ; i++){
			if (!Ethoni[i] && !Ethoni[N-i]){
				cout << i << " " << N-i << endl;
				check = 1;
				break;
			}
		}
		if (check==0) cout << -1 << endl;
	}
	return 0;
}
