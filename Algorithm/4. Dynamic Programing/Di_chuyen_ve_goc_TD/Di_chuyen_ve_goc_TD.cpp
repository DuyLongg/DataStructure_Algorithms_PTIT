#include <bits/stdc++.h>
using namespace std;

long long T,N,M,F[30][30];

void Cal(){
	memset(F,0,sizeof(F));
	for (int i = 0 ; i <= 25 ; i++) F[i][0] = F[0][i] = 1;
	for (int i = 1 ; i <= 25 ; i++){
		for (int j = 1 ; j <= 25 ; j++){
			F[i][j] = F[i-1][j] + F[i][j-1];
		}
	}
}

int main (){
	cin >> T;
	Cal();
	while (T--){
		cin >> N >> M;
		cout << F[N][M] << endl;
	}
}
