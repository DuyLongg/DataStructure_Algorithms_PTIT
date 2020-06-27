#include <bits/stdc++.h>
using namespace std;

int T,V,E,x1,x2,daxet[1005],counts,tmp;
unordered_map <int,vector<int>> Box;

void Input (){
	cin >> V >> E;
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
		tmp = Q.front(); Q.pop();
		for (int i = 0 ; i < Box[tmp].size() ; i++){
			if (daxet[Box[tmp][i]] == 0){ // chua xet
				daxet[Box[tmp][i]] = 1;
				Q.push(Box[tmp][i]);
			}
		}
	}
}

int TPLT (){
	counts = 0;
	for (int i = 1 ; i <= V ; i++){
		if (daxet[i] == 0){
			counts++;
			BFS(i);
		}
	}
	return counts;
}

int main (){
	cin >> T;
	while (T--){
		memset(daxet,0,sizeof(daxet));
		Box.clear();
		Input();
		cout << TPLT() << endl;
	}
	return 0;
}
