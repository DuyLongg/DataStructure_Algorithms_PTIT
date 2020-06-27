#include <bits/stdc++.h>
using namespace std;

int T,V,E,x1,x2,daxet[1005];
unordered_map <int,vector<int>> Box;

void Input (){
	cin >> V >> E;
	for (int i = 1 ; i <= E ; i++){
		cin >> x1 >> x2;
		Box[x1].push_back(x2); 
		Box[x2].push_back(x1); 
	}
}

void BFS (int u){
	queue <int> Q;
	Q.push(u);
	daxet[u] = 1;
	while (!Q.empty()){
		x1 = Q.front(); Q.pop();
		for (int i = 0 ; i < Box[x1].size() ; i++){
			if (daxet[Box[x1][i]] == 0){ // chua xet
				daxet[Box[x1][i]] = 1;
				Q.push(Box[x1][i]);
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

void DinhTru (){
	for (int i = 1 ; i <= V ; i++){
		memset (daxet,0,sizeof(daxet));
		daxet[i] = 1;
		if (i == 1) BFS(2);
		else BFS(1);
		if (IsDuyetHet() == false) cout << i << " ";
	}
}

int main (){
	cin >> T;
	while (T--){
		Box.clear();
		Input();
		DinhTru();
		cout << endl;
	}
	return 0;
}
