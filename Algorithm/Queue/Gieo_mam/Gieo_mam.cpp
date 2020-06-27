#include <bits/stdc++.h>
using namespace std;

struct node{
	int i,j;
	int day;
};

int R,C,A[505][505],day_need = 0;
queue <node> B;
node tmp;

void Input(){
	cin >> R >> C;
	for (int i = 1 ; i <= R ; i++){
		for (int j = 1 ; j <= C ; j++){
			cin >> A[i][j];
			if (A[i][j] == 2) B.push({i,j,0});
		}
	}
}

bool moc_het (){
	for (int i = 1 ; i <= R ; i++){
		for (int j = 1 ; j <= C ; j++){
			if (A[i][j] == 1) return false;
		}
	}
	return true;
}

int BFS (){
	while (!B.empty()){
		tmp = B.front(); B.pop();
		day_need = max (day_need,tmp.day);
		if (A[tmp.i-1][tmp.j] == 1){ // xet phan tu phia tren
			A[tmp.i-1][tmp.j] = 2; 	// hat da moc mam
			B.push({tmp.i-1,tmp.j,tmp.day+1});
		}
		if (A[tmp.i][tmp.j-1] == 1){ // xet phan tu phia trai
			A[tmp.i][tmp.j-1] = 2;
			B.push({tmp.i,tmp.j-1,tmp.day+1});
		}
		if (A[tmp.i+1][tmp.j] == 1){ // xet phan tu phia duoi
			A[tmp.i+1][tmp.j] = 2;
			B.push({tmp.i+1,tmp.j,tmp.day+1});
		}
		if (A[tmp.i][tmp.j+1] == 1){ // xet phan tu phia phai
			A[tmp.i][tmp.j+1] = 2;
			B.push({tmp.i,tmp.j+1,tmp.day+1});
		}
	}
	if (moc_het()) return day_need;
	else return -1;
}

int main (){
	Input();
	cout << BFS() << endl;	
	return 0;
}
