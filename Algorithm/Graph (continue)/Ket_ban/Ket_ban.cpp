#include <bits/stdc++.h>
using namespace std;

int T,N,M,u,v,daxet[100005],maxHS;
unordered_map <int, vector<int>> Box;

void Input(){
	cin >> N >> M;
	for (int i = 1 ; i <= M ; i++){
		cin >> u >> v;
		Box[u].push_back(v); 
		Box[v].push_back(u);
	}
}

int DFS (int u){
	daxet[u] = 1; 
	int ans = 1;
	for (int i = 0 ; i < Box[u].size() ; i++){
		if (!daxet[Box[u][i]]){
			ans += DFS(Box[u][i]);
		}
	}
	return ans;
}

int Solve (){
	maxHS = 1;
	memset(daxet,0,sizeof(daxet));
	for (int i = 1 ; i <= N ; i++){
		if (!daxet[i]){
			maxHS = max (maxHS, DFS(i));
		}
	}
	return maxHS;
}

int main (){
	cin >> T;	
	while (T--){
		Box.clear();
		Input();
		cout << Solve() << endl;
	}
	return 0;
}
