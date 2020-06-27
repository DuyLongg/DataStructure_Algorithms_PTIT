#include <bits/stdc++.h>
using namespace std;
// bai nay can chung minh lien thong
int T,N,u,v,daxet[1005];
unordered_map <int,vector<int>> Box;

void Input(){
	cin >> N;
	for (int i = 1 ; i < N ; i++){
		cin >> u >> v;	
		Box[u].push_back(v);
		Box[v].push_back(u);
	}
}

void DFS(int u){ // p la cha cua u
	daxet[u] = 1;
	for (int v = 0 ; v < Box[u].size() ; v++){
		if (!daxet[Box[u][v]]) DFS(Box[u][v]);
	}
}

void Solve (){
	memset (daxet,0,sizeof(daxet));
	DFS(1);
}

bool IsDuyetHet(){
	for (int i = 1 ; i <= N ; i++){
		if (daxet[i] == 0) return false;
	}
	return true;
}

int main (){
	cin >> T;
	while (T--){
		Box.clear();
		Input();
		Solve();
		if (IsDuyetHet()) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}
