#include <bits/stdc++.h>
using namespace std;

int T,m,n,p,F[105][105][105];// L[m][n][p] la dap an
string X,Y,Z;

int Solve (){
	int i,j,k;
	memset(F,0,sizeof(F));
	for (i = 1 ; i <= m ; i++){
		for (j = 1 ; j <= n ; j++){
			for (k = 1 ; k <= p ; k++){
				if (X[i-1]==Y[j-1] && Y[j-1]==Z[k-1]) F[i][j][k] = F[i-1][j-1][k-1] + 1;
				else F[i][j][k] = max (F[i-1][j][k],max(F[i][j-1][k],F[i][j][k-1]));
			}
		}
	}
	return F[m][n][p];
}

int main (){
	cin >> T;
	while (T--){
		cin >> m >> n >> p;
		cin >> X >> Y >> Z;
		cout << Solve() << endl;
	}
	return 0;
}
