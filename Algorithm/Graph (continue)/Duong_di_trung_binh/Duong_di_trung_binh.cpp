#include <bits/stdc++.h>
#define oo 100000000
using namespace std;

int T,N,M,u,v,A[105][105],D[105][105];
// D[u][v] la duong di ngan nhat tu dinh u toi dinh v
void Input(){
	memset(A,0,sizeof(A));
	cin >> N >> M;
	for (int i = 1 ; i <= M ; i++){
		cin >> u >> v;
		A[u][v] = 1;	// v ke voi u 
	}
}

void Floy (){
	for (int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= N ; j++){
			if (i==j) D[i][j] = 0;
			else if (A[i][j] == 1) D[i][j] = A[i][j]; 
			else D[i][j] = oo;
		}
	}
	for (int k = 1 ; k <= N ; k++){
		for (int i = 1 ; i <= N ; i++){
			for (int j = 1 ; j <= N ; j++){
				if (D[i][j] > D[i][k] + D[k][j]){
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
}

void Cal (){
	double sum = 0;
	double socanh = 0;
	for (int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= N ; j++){
			if (D[i][j] > 1000000 || i==j) continue; // neu D[i][j] > 1000000 tuc la khong co duong di tu i toi j 
			sum += D[i][j];
			socanh++;
		}
	}
	printf ("%.2f\n",sum/socanh);
}

int main (){
	cin >> T;
	while (T--){
		Input();
		Floy();
		Cal();
	}
	return 0;
}
