// 2563
// 2 5 6 3
// 25 6 3
#include <bits/stdc++.h>
using namespace std;

int T,F[45]; // F[N] la so cach ma hoa M phan tu dau
string M;

int Solve(){
	memset (F,0,sizeof(F));
	F[0] = F[1] = 1;
	if (M[0] == '0') return 0;
	for (int i = 2 ; i <= M.size() ; i++){
		if (M[i-1] > '0') F[i] = F[i-1];
		if ((M[i-2] == '1') || (M[i-2] == '2' && M[i-1] <= '6')) F[i] = F[i] + F[i-2];
	}
	return F[M.size()];
}

int main (){
	cin >> T;
	while (T--){
		cin >> M;
		cout << Solve() << endl;
	}
	return 0;
}
