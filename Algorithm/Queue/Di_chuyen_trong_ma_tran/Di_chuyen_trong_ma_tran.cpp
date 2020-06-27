#include <bits/stdc++.h>
using namespace std;

int T,M,N,A[1005][1005],level[1005][1005],i_next,j_next,daxet[1005][1005];

struct node { // tao node de luu index i,j
	int i,j;
};

node tmp;

void Input (){
	cin >> M >> N;
	for (int i = 1 ; i <= M ; i++){
		for (int j = 1 ; j <= N ; j++){
			cin >> A[i][j];
		}
	}
}

int BFS (){
	memset(level,0,sizeof(level));
	memset (daxet,0,sizeof(daxet));
	queue <node> B;
	daxet[1][1] = 1;
	B.push ({1,1}); 
//	level[1][1] = 0;
	while (!B.empty()){
		tmp = B.front(); B.pop();
		if (tmp.i == M && tmp.j == N) return level[M][N]; // So buoc de di tu A[1][1] -> A[M][N]
		j_next = tmp.j+A[tmp.i][tmp.j];
		if (j_next <= N && daxet[tmp.i][j_next] == 0) {
			B.push({tmp.i,j_next});
			daxet[tmp.i][j_next] = 1;
			level[tmp.i][j_next] = level[tmp.i][tmp.j] + 1;
		}
		i_next = tmp.i+A[tmp.i][tmp.j];
		if (i_next <= M && daxet[i_next][tmp.j] == 0) {
			B.push({i_next,tmp.j});
			daxet[i_next][tmp.j] = 1;
			level[i_next][tmp.j] = level[tmp.i][tmp.j] + 1;
		}
	}
	return -1;
}

int main (){
	cin >> T;
	while (T--){
		Input();
		cout << BFS() << endl;
	}
	return 0;
}
