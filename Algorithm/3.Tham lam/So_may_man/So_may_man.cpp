#include <iostream>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		for (int i = n/7 ; i >= 0 ; i--){
			if ((n-i*7)%4==0){
				for (int p = (n-i*7)/4 ; p > 0 ; p--) cout << 4;
				for (int j = i ; j > 0 ; j--) cout << 7;
				cout << endl;
				n = 0;
				break;
			}
		}
		if (n!=0) cout << -1 << endl;
	}
	return 0;
}
