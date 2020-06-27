#include <bits/stdc++.h>
using namespace std;

int T,V,E,x1,x2,daxet[1005];
bool cycle;
unordered_map<int,vector<int>> Box;

void Input (){
	cin >> V >> E;
	for (int i = 1 ; i <= E ; i++){
		cin >> x1 >> x2;
		Box[x1].push_back(x2);
	}
}

void DFS (int u){
	daxet[u] = 1;
	for (int v = 0 ; v < Box[u].size() ; v++){
		if (daxet[Box[u][v]] == 0) DFS(Box[u][v]);
		if (daxet[Box[u][v]] == 1) cycle = true;
	}
	daxet[u] = 2;
}

void Solve(){
	cycle = false;
	memset(daxet,0,sizeof(daxet));
	for (int i = 1 ; i <= V ; i++){
		if (!daxet[i]) DFS(i);
		if (cycle == true) return;
	}
}

int main (){
	cin >> T;
	while (T--){
		Box.clear();
		Input();
		Solve();
		if (cycle == true) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}
