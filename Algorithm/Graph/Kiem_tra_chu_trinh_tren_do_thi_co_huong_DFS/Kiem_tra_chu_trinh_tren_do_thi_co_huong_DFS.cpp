#include <bits/stdc++.h>
using namespace std;

int T,V,E,x1,x2,daxet[1005],truoc[1005];
unordered_map <int, vector <int>> Box;

void Input(){
	cin >> V >> E;
	for (int i = 1 ; i <= E ; i++){
		cin >> x1 >> x2;
		Box[x1].push_back(x2);
//		Box[x2].push_back(x1);
	}
}

bool cycle;

void DFS (int u){
	daxet[u] = 1;
	for (int i = 0 ; i < Box[u].size() ; i++){
		if (daxet[Box[u][i]] == 0){ // dinh ke chua xet
			DFS(Box[u][i]);
		} else if (daxet[Box[u][i]] == 1) cycle = true;
	}
	daxet[u] = 2;
}

int main (){
	cin >> T;
	while (T--){
		memset(truoc,0,sizeof(truoc));
		memset(daxet,0,sizeof(daxet));
		Box.clear(); cycle = false;
		Input();
		DFS(1);
		if (cycle == true) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
