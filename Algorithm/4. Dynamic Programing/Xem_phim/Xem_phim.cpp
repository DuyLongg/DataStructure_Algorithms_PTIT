#include <bits/stdc++.h>
using namespace std;

int C,N,A[105],F[105][25005]; // F[N][C] la khoi luong bo lon nhat co trong gioi ham C (trong N con bo dau tien)
// F[i][j] la khoi luong bo lon nhat co the mang di trong gioi han j (trong i con bo dau tien)
// F[i][j] = max (F[i][j],F[i-1][j-A[i]] + A[i]);
int Solve (){
	memset(F,0,sizeof(F));
	for (int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= C ; j++){
			F[i][j] = F[i-1][j];
			if (j >= A[i]) F[i][j] = max (F[i][j],F[i-1][j-A[i]] + A[i]);
		}
	}
	return F[N][C];
}

int main (){
	cin >> C >> N;
	for (int i = 1 ; i <= N ; i++) cin >> A[i];
	cout << Solve() << endl;
	return 0;
}
