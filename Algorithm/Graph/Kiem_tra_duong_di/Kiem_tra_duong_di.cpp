#include <bits/stdc++.h>
using namespace std;

int T,N,M,x1,x2,Q,daxet[1005],truoc[1005],node;
unordered_map <int, vector <int>> Box;

void BFS (int u){
	queue <int> Q;
	Q.push(u);
	daxet[u] = 1;
	while (!Q.empty()){
		node = Q.front(); Q.pop();
		for (int i = 0 ; i < Box[node].size() ; i++){
			if (daxet[Box[node][i]] == 0){ // chua xet
				daxet[Box[node][i]] = 1;
				truoc[Box[node][i]] = x1;
				Q.push(Box[node][i]);
			}
		}
	}
}

void Input (){
	cin >> N >> M;
	for (int i = 1 ; i <= M ; i++){
		cin >> x1 >> x2;
		Box[x1].push_back(x2);
		Box[x2].push_back(x1);
	}
	cin >> Q; // so truy van
}

void Tim_duong (){
	if (truoc[x2]) cout << "YES" ;
	else cout << "NO";
}

void Solve(){
	while (Q--){
		memset(truoc,0,sizeof(truoc));
		memset(daxet,0,sizeof(daxet));
		cin >> x1 >> x2;
		BFS(x1);
		Tim_duong();
		cout << endl;
	}
}

int main (){
	cin >> T;
	while (T--){
		Box.clear();
		Input();
		Solve();
	}
	return 0;
}
