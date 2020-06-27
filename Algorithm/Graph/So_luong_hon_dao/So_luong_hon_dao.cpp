#include <bits/stdc++.h>
using namespace std;

struct node {
	int i,j;
};

int T,A[505][505],N,M,counts;
node key;
vector <node> vt;

void Input(){
	cin >> N >> M;
	for (int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= M ; j++){
			cin >> A[i][j];
			if (A[i][j]) {
				vt.push_back({i,j});
			}
		}
	}
}

void BFS (node B){
	queue <node> Q;
	Q.push(B);
	while (!Q.empty()){
		key = Q.front(); Q.pop();
		if (key.i+1 <= N && A[key.i+1][key.j] == 1){
			A[key.i+1][key.j] = 0;
			Q.push({key.i+1,key.j});
		}
		if (key.i-1 >= 1 && A[key.i-1][key.j] == 1){
			A[key.i-1][key.j] = 0;
			Q.push({key.i-1,key.j});
		}
		if (key.j+1 <= M && A[key.i][key.j+1] == 1){
			A[key.i][key.j+1] = 0;
			Q.push({key.i,key.j+1});
		}
		if (key.j-1 >= 1 && A[key.i][key.j-1] == 1){
			A[key.i][key.j-1] = 0;
			Q.push({key.i,key.j-1});
		}
		if (key.i-1 >= 1 && key.j-1 >= 1 && A[key.i-1][key.j-1] == 1){
			A[key.i-1][key.j-1] = 0;
			Q.push({key.i-1,key.j-1});
		}
		if (key.i+1 <= N && key.j+1 <= M && A[key.i+1][key.j+1] == 1){
			A[key.i+1][key.j+1] = 0;
			Q.push({key.i+1,key.j+1});
		}
		if (key.i-1 >= 1 && key.j+1 <= M && A[key.i-1][key.j+1] == 1){
			A[key.i-1][key.j+1] = 0;
			Q.push({key.i-1,key.j+1});
		}
		if (key.i+1 <= N && key.j-1 >= 1 && A[key.i+1][key.j-1] == 1){
			A[key.i+1][key.j-1] = 0;
			Q.push({key.i+1,key.j-1});
		}
	}
}

int Solve(){
	counts = 0;
	for (int r = 0 ; r < vt.size() ; r++){
		if (A[vt[r].i][vt[r].j]) {
			BFS({vt[r].i,vt[r].j});
			counts++;
		}
	}
	return counts;
}

int main (){
	cin >> T;
	while (T--){
		vt.clear();
		Input();
		cout << Solve() << endl; 
	}
	return 0;
}
