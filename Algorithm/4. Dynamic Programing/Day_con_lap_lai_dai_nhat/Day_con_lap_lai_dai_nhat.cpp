#include <bits/stdc++.h>
using namespace std;

int T,N,F[105][105];
string S;
// L[i][j] la xau con chung dai nhat trong khoang x1,..xi va y1,...yj 
int Solve(){
	int i,j;
	for (i = 0 ; i <= N ; i++) F[i][0] = F[0][i] = 0;
	for (i = 1 ; i <= N ; i++){
		for (j = 1 ; j <= N ; j++){
			if (S[i-1]==S[j-1] && i!=j) F[i][j] = F[i-1][j-1] + 1;
			else F[i][j] = max (F[i-1][j],F[i][j-1]);
		}
	}
	return F[N][N];
}

int main (){
	cin >> T;
	while (T--){
		cin >> N >> S;
		cout << Solve() << endl;
	}
	return 0;
}
