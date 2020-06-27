#include <iostream>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		string B; cin >> B;
		for (int i = B.length()-1 ; i >= 0 ; i--) {
			if (B[i] == '1') B[i] = '0';
			else {
				B[i] = '1';
				break;
			}
		}
		cout << B << endl;
	}
	return 0;
}
