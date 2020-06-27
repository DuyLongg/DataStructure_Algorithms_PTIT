#include <bits/stdc++.h>
using namespace std;

int T,A,B,C;
char D[35][35][35];
int daxet[35][35][35];

struct node {
	int i,j,k;
	int dodai;
};

node S,E,tmp;

void Input(){
	cin >> A >> B >> C;
	for (int i = 1 ; i <= A ; i++){
		for (int j = 1 ; j <= B ; j++){
			for (int k = 1 ; k <= C ; k++){
				cin >> D[i][j][k];
				if (D[i][j][k] == 'S') {
					S.i = i; S.j = j; S.k = k;
					S.dodai = 0;
				} 
				if (D[i][j][k] == 'E'){
					E.i = i; E.j = j; E.k = k;
				}
			}
		}
	}
}

void In(){
	for (int i = 1 ; i <= A ; i++){
		for (int j = 1 ; j <= B ; j++){
			for (int k = 1 ; k <= C ; k++){
				cout << D[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

int BFS (){
	memset(daxet,0,sizeof(daxet));
	queue <node> Q;
	Q.push(S);
	daxet[S.i][S.j][S.k] = 1;
	while (!Q.empty()){
		tmp = Q.front(); Q.pop();
		if (tmp.i == E.i && tmp.j == E.j && tmp.k == E.k) return tmp.dodai;
		if (tmp.i-1 >= 1 && daxet[tmp.i-1][tmp.j][tmp.k] == 0 && D[tmp.i-1][tmp.j][tmp.k] != '#'){
			daxet[tmp.i-1][tmp.j][tmp.k] = 1;
			Q.push({tmp.i-1,tmp.j,tmp.k,tmp.dodai+1});
		}
		if (tmp.i+1 <= A && daxet[tmp.i+1][tmp.j][tmp.k] == 0 && D[tmp.i+1][tmp.j][tmp.k] != '#'){
			daxet[tmp.i+1][tmp.j][tmp.k] = 1;
			Q.push({tmp.i+1,tmp.j,tmp.k,tmp.dodai+1});
		}
		if (tmp.j-1 >= 1 && daxet[tmp.i][tmp.j-1][tmp.k] == 0 && D[tmp.i][tmp.j-1][tmp.k] != '#'){
			daxet[tmp.i][tmp.j-1][tmp.k] = 1;
			Q.push({tmp.i,tmp.j-1,tmp.k,tmp.dodai+1});
		}
		if (tmp.j+1 <= B && daxet[tmp.i][tmp.j+1][tmp.k] == 0 && D[tmp.i][tmp.j+1][tmp.k] != '#'){
			daxet[tmp.i][tmp.j+1][tmp.k] = 1;
			Q.push({tmp.i,tmp.j+1,tmp.k,tmp.dodai+1});
		}
		if (tmp.k-1 >= 1 && daxet[tmp.i][tmp.j][tmp.k-1] == 0 && D[tmp.i][tmp.j][tmp.k-1] != '#'){
			daxet[tmp.i][tmp.j][tmp.k-1] = 1;
			Q.push({tmp.i,tmp.j,tmp.k-1,tmp.dodai+1});
		}
		if (tmp.k+1 <= C && daxet[tmp.i][tmp.j][tmp.k+1] == 0 && D[tmp.i][tmp.j][tmp.k+1] != '#'){
			daxet[tmp.i][tmp.j][tmp.k+1] = 1;
			Q.push({tmp.i,tmp.j,tmp.k+1,tmp.dodai+1});
		}
	}
	return -1;
}

int main (){
	cin >> T;
	while (T--){
		Input();
//		In();
		cout << BFS() << endl;
	}
	return 0;
}
