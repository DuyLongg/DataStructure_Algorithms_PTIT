#include <bits/stdc++.h>
using namespace std;

int Matran_ke[30][30];// E la tap dinh
int N,M,len_max = 0;

void Input (){
	memset (Matran_ke,0,sizeof(Matran_ke));
	cin >> N >> M;
	int x,y;
	for (int i = 0 ; i < M ; i++){
		cin >> x >> y;
		Matran_ke[x][y] = Matran_ke[y][x] = 1;
	}
}

void DFS (int u,int len){
	len_max = max(len,len_max);
	for (int v = 0 ; v < N ; v++){
		if (Matran_ke[u][v]){
			Matran_ke[u][v] = Matran_ke[v][u] = 0;
			DFS (v,len+1);
			Matran_ke[u][v] = Matran_ke[v][u] = 1;
		}
	}
}

int main (){
	int T; cin >> T;
	while (T--){
		Input();
		for (int i = 0 ; i < N ; i++) DFS (i,0);
		cout << len_max << endl;
		len_max = 0;
	}
	return 0;
}
