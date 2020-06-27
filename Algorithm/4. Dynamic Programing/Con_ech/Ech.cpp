#include <bits/stdc++.h>
using namespace std;

long long T,N,L[55];

void Solve (){
	L[1] = 1; L[2] = 2; L[3] = 4;
	for (int i = 4 ; i < 55 ; i++){
		L[i] = L[i-1] + L[i-2] + L[i-3];
	}
}

int main (){
	cin >> T;
	Solve();
	while (T--){
		cin >> N;
		cout << L[N] << endl;
	}
	return 0;
}
