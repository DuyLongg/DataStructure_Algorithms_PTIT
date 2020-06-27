#include <iostream>
using namespace std;

int main (){
	int T; cin >> T;
	string A;
	while (T--){
		cin >> A;
		int stt = 0;
		for (int i = 0 ; i < A.size() ; i++){
			if (stt == 0) {
				cout << A[i];
				if (A[i] == '1') stt = 1;
			}
			else {
				if (A[i] == '0') {
					cout << '1';
					stt = 0;
				}
				else cout << '0';
			}
		}
		cout << endl;
	}
	return 0;
}
