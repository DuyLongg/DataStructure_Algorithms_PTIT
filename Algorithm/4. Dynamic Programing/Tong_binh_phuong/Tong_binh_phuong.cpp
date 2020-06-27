#include <bits/stdc++.h>
using namespace std;

long long T,N,F[10005];

void Solve(){
	int i,j;
	F[0] = 0; F[1] = 1; F[2] = 2; F[3] = 3;
	for (i = 4 ; i <= 10000 ; i++){
		F[i] = i;
		for (j = 1 ; j <= sqrt(i) ; j++){
			F[i] = min (F[i],F[i-j*j] + 1);
		}
	}
}

int main (){
	cin >> T;
	Solve();
	while (T--){
		cin >> N;
		cout << F[N] << endl;
	}
	return 0;
}
