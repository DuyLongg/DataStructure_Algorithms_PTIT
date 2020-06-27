#include <iostream>
#include <math.h>
using namespace std;

void Gray (int C,int N){
	int r[N] = {0};
	int tmp = N;
	do{
		r[tmp-1] = C%2;
		tmp--; 
		C = C/2;
	} while (C!=0);
	for (int i = 0 ; i < N ; i++) cout << r[i];
	cout << " ";
}

int main (){
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		int C; 
		for (int i = 0  ; i < pow(2,N) ; i++){
			C = i ^ (i >> 1);
			Gray (C,N);
		}
		cout << endl;
	}
	return 0;
}

