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

void DFS (int u){
	daxet[u] = 1;
	for (int i = 0 ; i < Box[u].size() ; i++){
		if (daxet[Box[u][i]] == 0) { // chua xet
			DFS(Box[u][i]);
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
		if (i == 1) DFS(2);
		else DFS(1);
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
