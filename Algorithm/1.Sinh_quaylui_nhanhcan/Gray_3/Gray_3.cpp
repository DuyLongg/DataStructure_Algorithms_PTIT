#include <iostream>
using namespace std;

int main (){
	int T; cin >> T;
	string A;
	while (T--){
		cin >> A;
		cout << A[0];
		char pre = A[0];
		for (int i = 1 ; i < A.size() ; i++){
			if (A[i] == '1') {
				if (pre == '0') {
					cout << '1';
					pre = '1';
				} else {
					cout << '0';
					pre = '0';
				}
			} else cout << pre;
		}
		cout << endl;
	}
	return 0;
}
