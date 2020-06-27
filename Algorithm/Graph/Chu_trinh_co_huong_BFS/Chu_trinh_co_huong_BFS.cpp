#include <bits/stdc++.h>
using namespace std;

int T,V,E,x1,x2,daxet[1005],key,parent[1005]; // tao mang parent de khi gap dinh da xet thi duyet nguoc lai xem dinh nay co tren truc da xet khong
bool cycle;
unordered_map<int,vector<int>> Box;

void Input (){
	cin >> V >> E;
	for (int i = 1 ; i <= E ; i++){
		cin >> x1 >> x2;
		Box[x1].push_back(x2);
	}
}

void BFS (int u){
	memset(parent,-1,sizeof(parent));
	queue <int> Q;
	Q.push(u);
	daxet[u] = 1;
	while (!Q.empty()){
		key = Q.front(); Q.pop();	
		for (int i = 0 ; i < Box[key].size() ; i++){
			parent[Box[key][i]] = key;
			if (key == Box[key][i]){
				cycle = true;
				return;
			}
			if (daxet[Box[key][i]]){
				int r = parent[Box[key][i]];
				while (parent[r] != -1){
					if (r == Box[key][i]){
						cycle = true;
						return;
					}
					r = parent[r];
				}
				if (Box[key][i] == r) cycle = true;
			} else {
				daxet[Box[key][i]] = 1;
				Q.push(Box[key][i]);
			}
		}
	}
}

void Solve(){
	cycle = false;
	memset(daxet,0,sizeof(daxet));
	for (int i = 1 ; i <= V ; i++){
		if (!daxet[i]) BFS(i);
		if (cycle == true) return;
	}
}

int main (){
	cin >> T;
	while (T--){
		Box.clear();
		Input();
		Solve();
		if (cycle == true) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}
