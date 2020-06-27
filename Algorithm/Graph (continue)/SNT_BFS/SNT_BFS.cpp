#include <bits/stdc++.h>
using namespace std;

int T,N,M,u,a,b,daxet[1005];
unordered_map <int,vector<int>> Box;
vector <pair<int,int>> E; // tap canh SNT

void Input (){
	cin >> N >> M >> u; // N = V | M = E | u = root
	for (int i = 1 ; i <= M ; i++){
		cin >> a >> b;
		Box[a].push_back(b);
		Box[b].push_back(a);
	}
}

void BFS (int u){
	queue <int> Q;
	Q.push(u);
	daxet[u] = 1;
	while (!Q.empty()){
		a = Q.front(); Q.pop();
		for (int i = 0 ; i < Box[a].size() ; i++){
			if (!daxet[Box[a][i]]){
				E.push_back(make_pair(a,Box[a][i]));
				daxet[Box[a][i]] = 1;
				Q.push(Box[a][i]);
			}
		}
	}
}

int SNT (){
	memset (daxet,0,sizeof(daxet));
	BFS(u);
	if (E.size() < N-1) cout << -1 << endl;
	else {
		for (int i = 0 ; i < E.size() ; i++){
			cout << E[i].first << " " << E[i].second << endl;
		}
	}
}

int main (){
	cin >> T;
	while (T--){
		Box.clear(); E.clear();
		Input();
		SNT();
	}
	return 0;
}
