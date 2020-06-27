#include <bits/stdc++.h>
using namespace std;

int T,V,E,u,x1,x2,daxet[1005];
unordered_map <int, vector <int>> Box;

void Input(){
	cin >> V >> E >> u;
	for (int i = 1 ; i <= E ; i++){
		cin >> x1 >> x2;
		Box[x1].push_back(x2);
	}
}

void BFS (int u){
	queue <int> Q;
	Q.push(u);
	daxet[u] = 1;
	while (!Q.empty()){
		x1 = Q.front(); Q.pop();
		cout << x1 << " ";
		for (int i = 0 ; i < Box[x1].size() ; i++){
			if (daxet[Box[x1][i]] == 0){ // chua xet
				daxet[Box[x1][i]] = 1;
				Q.push(Box[x1][i]);
			}
		}
	}
}

int main (){
	cin >> T;
	while (T--){
		memset(daxet,0,sizeof(daxet));
		Box.clear();
		Input();
		BFS(u);
		cout << endl;
	}
	return 0;
}
