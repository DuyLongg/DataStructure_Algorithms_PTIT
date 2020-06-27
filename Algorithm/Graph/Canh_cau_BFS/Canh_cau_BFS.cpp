#include <bits/stdc++.h>
using namespace std;

int T,V,E,x1,x2,A[1005][1005],daxet[1005],tmp;

void Input (){
	cin >> V >> E;
	memset(A,0,sizeof(A));
	for (int i = 1 ; i <= E ; i++){
		cin >> x1 >> x2;
		A[x1][x2] = A[x2][x1] = 1;
	}
}

void BFS (int u){
	queue <int> B;
	B.push(u);
	daxet[u] = 1;
	while (!B.empty()){
		tmp = B.front(); B.pop();
		for (int i = 1 ; i <= V ; i++){
			if (A[tmp][i] == 1 && daxet[i] == 0){
				daxet[i] = 1;
				B.push(i);
			}
		}
	}
}

bool IsDuyetHet(){
	for (int i = 1 ; i <= V ; i++){
		if (daxet[i] == 0) return false;
	}
	return true;
}

void CanhCau (){
	for (int i = 1 ; i < V ; i++){
		for (int j = i+1 ; j <= V ; j++){
			if (A[i][j] == 1){
				memset(daxet,0,sizeof(daxet));
				A[i][j] = A[j][i] = 0;
				BFS(1);
				if (IsDuyetHet() == false) cout << i << " " << j << " ";
				A[i][j] = A[j][i] = 1;
			}
		}
	}
}

int main (){
	cin >> T;
	while (T--){
		Input();
		CanhCau();
		cout << endl;
	}
	return 0;
}
