#include <bits/stdc++.h>
using namespace std;

int T,V,E,x1,x2,daxet[1005];
bool cycle;
unordered_map <int,vector<int>> Box;

void Input(){ 
	cin >> V >> E;
	for (int i = 1 ; i <= E ; i++){
		cin >> x1 >> x2;
		Box[x1].push_back(x2);
		Box[x2].push_back(x1);
	}
}

void DFS(int u, int p){ // p la cha cua u
	daxet[u] = 1;
	for (int v = 0 ; v < Box[u].size() ; v++){
		if (daxet[Box[u][v]] && Box[u][v] != p) cycle = true;
		if (!daxet[Box[u][v]]) DFS(Box[u][v],u);
	}
}

void Solve(){
	memset(daxet,0,sizeof(daxet));
	for (int u = 1 ; u <= V ; u++){
		if (!daxet[u]) DFS(u,u);
		if (cycle == true) return;
	}
}

int main (){
	cin >> T;
	while (T--){
		cycle = false; 
		Box.clear();
		Input();
		Solve();
		if (cycle == true) cout << "YES";// neu co chu ki
		else cout << "NO";
		cout << endl;
	}
	return 0;
}
