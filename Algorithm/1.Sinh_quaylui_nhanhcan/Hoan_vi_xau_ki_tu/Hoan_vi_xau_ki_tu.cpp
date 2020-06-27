#include <iostream>
using namespace std;

int chuaxet[29] = {0};
string A; char B[29];

void In(){
	for (int i = 0 ; i < A.size() ; i++) cout << B[i];
	cout << " ";
}

void Back_track (int i){
	for (int j = 0 ; j < A.size() ; j++){
		if (chuaxet[j]==0){
			B[i] = A[j];
			chuaxet[j] = 1;
			if (i==A.size()-1) In();
			else Back_track(i+1);
			chuaxet[j] = 0;
		}
	}
}

int main (){
	int T; cin >> T;
	while (T--){
		cin >> A;
		Back_track(0);
		cout << endl;
	}
	return 0;
}
