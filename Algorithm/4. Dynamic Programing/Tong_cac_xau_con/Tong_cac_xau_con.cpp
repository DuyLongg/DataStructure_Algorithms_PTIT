#include <bits/stdc++.h>
using namespace std;

long long T,F[15][15];
string N;
// code 1 cach ngu xuan =)
long long Solve (){
	// F[0][N_length-1] 
	memset (F,0,sizeof(F));
	long long sum = 0;
	for (int k = 0 ; k <= N.length()-1 ; k++){
		for (int i = 0 ; i <= N.length()-1-k ; i++){
			for (int j = i ; j <= i+k ; j++){
				F[i][i+k] = F[i][i+k]*10 + (N[j]-'0');
			}
			sum = sum + F[i][i+k];
		}
	}
	return sum;
}

int main (){
	cin >> T;
	while (T--){
		cin >> N;
		cout << Solve() << endl;
	}
	return 0;
}
