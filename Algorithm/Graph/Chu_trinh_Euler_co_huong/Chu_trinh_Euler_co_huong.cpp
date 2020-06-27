#include <bits/stdc++.h>
using namespace std;

int T,V,E,x1,x2,A[1005][1005],sum1;

void Input (){
	memset(A,0,sizeof(A));
	cin >> V >> E;
	for (int i = 1 ; i <= E ; i++){
		cin >> x1 >> x2;
		A[x1][x2] = 1;
	}
}

int sumH (int i){
	sum1 = 0;
	for (int j = 1 ; j <= V ; j++) sum1 = sum1 + A[i][j];
	return sum1; 
}

int sumC (int i){
	sum1 = 0;
	for (int j = 1 ; j <= V ; j++) sum1 = sum1 + A[j][i];
	return sum1; 
}

int Solve(){
	for (int i = 1 ; i <= V ; i++){
		if (sumH(i) != sumC(i)) return 0; // ban bac vao != ban bac ra thi khong phai la euler
	}
	return 1;
}

int main (){
	cin >> T;
	while (T--){
		Input();	
		cout << Solve() << endl;
	}
	return 0;
}
