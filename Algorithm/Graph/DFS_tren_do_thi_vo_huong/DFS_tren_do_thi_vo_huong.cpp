#include <bits/stdc++.h>
using namespace std;

int T,V,E,u,x1,x2,daxet[1005];
unordered_map <int, vector <int>> Box;

void Input(){
	cin >> V >> E >> u;
	for (int i = 1 ; i <= E ; i++){
		cin >> x1 >> x2;
		Box[x1].push_back(x2);
		Box[x2].push_back(x1);
	}
}

void DFS (int u){
	cout << u << " "; // duyet dinh u
	daxet[u] = 1;
	for (int i = 0 ; i < Box[u].size() ; i++){
		if (daxet[Box[u][i]] == 0){ // dinh ke chua xet
			DFS(Box[u][i]);
		}
	}
}

int main (){
	cin >> T;
	while (T--){
		memset(daxet,0,sizeof(daxet));
		Box.clear();
		Input();
		DFS(u);
		cout << endl;
	}
	return 0;
}
