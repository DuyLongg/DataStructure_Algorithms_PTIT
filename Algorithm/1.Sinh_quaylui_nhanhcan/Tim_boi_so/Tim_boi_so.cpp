#include <iostream>
using namespace std;

inline void Sinh (int a[]){
	for (int i = 16 ; i >= 0 ; i--){
		if (a[i] == 0){
			a[i] = 9;
			for (int j = i+1 ; j <= 16 ; j++){
				a[j] = 0;
			}
			break;
		}
	}
}

int main (){
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		int a[17] = {0};
		int r = 131071;
		while (r--){
			Sinh (a);
			long long kq = 0; 
			for (int i = 0 ; i < 17 ; i++){
				kq = kq*10 + a[i];
			}
			if (kq % N == 0) {
				cout << kq << endl;
				break;
			}
		}
	}
	return 0;
}
