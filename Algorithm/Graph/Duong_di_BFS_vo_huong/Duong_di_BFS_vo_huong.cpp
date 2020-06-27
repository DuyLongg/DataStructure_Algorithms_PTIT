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

void BFS (int u){
	queue <int> Q;
	Q.push(u);
	daxet[u] = 1;
	while (!Q.empty()){
		x1 = Q.front(); Q.pop();
		for (int i = 0 ; i < Box[x1].size() ; i++){
			if (daxet[Box[x1][i]] == 0){ // chua xet
				daxet[Box[x1][i]] = 1;
				truoc[Box[x1][i]] = x1;
				Q.push(Box[x1][i]);
			}
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
		BFS(u);
		Tim_duong();
		cout << endl;
	}
	return 0;
}
