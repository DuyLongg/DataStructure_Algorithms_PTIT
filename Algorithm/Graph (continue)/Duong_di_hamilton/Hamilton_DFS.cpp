#include <bits/stdc++.h>
using namespace std;

int T,V,E,u,v,daxet[15],nums;
unordered_map <int,vector<int>> Box;

void Input(){
	cin >> V >> E;
	for (int i = 1 ; i <= E ; i++){
		cin >> u >> v;
		Box[u].push_back(v);
		Box[v].push_back(u);
	}
}

bool DFS(int u, int nums){
	if (nums == V) return true;
	daxet[u] = 1;
	for (int i = 0 ; i < Box[u].size() ; i++){	
		if (!daxet[Box[u][i]]) {
			if (DFS(Box[u][i],nums+1)) return true;
		}
	}
	daxet[u] = 0;
	return false;
}

int IsHam(){
	memset(daxet,0,sizeof(daxet));
	for (int i = 1 ; i <= V ; i++){
		nums = 0;
		if (DFS(i,nums+1)) return 1;;
	}
	return 0;
}

int main (){
	cin >> T;
	while (T--){
		Box.clear();
		Input();
		cout << IsHam() << endl;
	}
	return 0;
}
