#include <bits/stdc++.h>
using namespace std;

int T,V,E,x1,x2,daxet[1005],parent[1005],node;
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

void BFS(int u){ // p la cha cua u
	queue <int> Q;
	Q.push(u);
	daxet[u] = 1;
	while (!Q.empty()){
		node = Q.front(); Q.pop();
		for (int v = 0 ; v < Box[node].size() ; v++){
			if (daxet[Box[node][v]] && Box[node][v] != parent[node]) cycle = true;
			if (!daxet[Box[node][v]]) {
				daxet[Box[node][v]] = 1;
				parent[Box[node][v]] = node;
				Q.push(Box[node][v]);
			}
		}
	}
}

void Solve(){
	memset(daxet,0,sizeof(daxet));
	for (int u = 1 ; u <= V ; u++){
		if (!daxet[u]) {
			parent[u] = u;
			BFS(u);
		}
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
