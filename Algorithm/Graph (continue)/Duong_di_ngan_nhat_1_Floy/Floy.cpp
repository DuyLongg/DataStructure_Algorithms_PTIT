#include <bits/stdc++.h>
#define INT_MAX 100000000
using namespace std;

int N,M,u,v,c,Q,A[1005][1005],D[1005][1005];
// D[u][v] la duong di ngan nhat giua 2 dinh u,v;
void Input(){
	cin >> N >> M; // N dinh - M canh
	for (int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= M ; j++){
			A[i][j] = INT_MAX;
		}
	}
	for (int i = 1 ; i <= M ; i++){
		cin >> u >> v >> c;
		A[u][v] = A[v][u] = c;
	}
	cin >> Q; // so luong truy van
}

void Floy(){
	for (int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= N ; j++){
			if (i==j) D[i][j] = 0;
			else if (A[i][j] != INT_MAX) D[i][j] = A[i][j];
			else D[i][j] = INT_MAX;
		}
	}
	for (int k = 1 ; k <= N ; k++){
		for (int i = 1 ; i <= N ; i++){
			for (int j = 1 ; j <= N ; j++){
				if (D[i][j] > D[i][k] + D[j][k]){
					D[i][j] = D[i][k] + D[j][k];
				}
			}
		}
	}
}

void Solve(){
	for (int i = 1 ; i <= Q ; i++){
		cin >> u >> v; // tim duong di ngan nhat giua u va v
		cout << D[u][v] << endl;
	}
}

int main (){
	Input();
	Floy();
	Solve();
	return 0;
}
