#include <bits/stdc++.h>
using namespace std;

int T,V,E,u,v,x1,x2,daxet[1005],truoc[1005];
unordered_map <int, vector <int>> Box;

void Input(){
	cin >> V >> E >> u >> v;
	for (int i = 1 ; i <= E ; i++){
		cin >> x1 >> x2;
		Box[x1].push_back(x2);
		Box[x2].push_back(x1);
	}
}

void DFS (int u){
//	cout << u << " "; // duyet dinh u
	daxet[u] = 1;
	for (int i = 0 ; i < Box[u].size() ; i++){
		if (daxet[Box[u][i]] == 0){ // dinh ke chua xet
			truoc[Box[u][i]] = u;
			DFS(Box[u][i]);
		}
	}
}

void Tim_duong (){
	if (truoc[v] == 0){ // khong co duong di tu u toi t
		cout << -1;
		return;
	}
	stack <int> path;
	path.push(v);
	while (truoc[v] != u){
		v = truoc[v];
		path.push(v);
	} 
	path.push(u);
	while (!path.empty()){
		cout << path.top() << " ";
		path.pop();
	}
}

int main (){
	cin >> T;
	while (T--){
		memset(truoc,0,sizeof(truoc));
		memset(daxet,0,sizeof(daxet));
		Box.clear();
		Input();
		DFS(u);
		Tim_duong();
		cout << endl;
	}
	return 0;
}
