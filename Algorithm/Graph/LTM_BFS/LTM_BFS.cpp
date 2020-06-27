#include <bits/stdc++.h>
using namespace std;

int T,V,E,x1,x2,daxet[1005];
unordered_map <int,vector<int>> Box1;
unordered_map <int,vector<int>> Box2;

void Input (){
	cin >> V >> E;
	for (int i = 1 ; i <= E ; i++){
		cin >> x1 >> x2;
		Box1[x1].push_back(x2); // luu huong mui ten theo chieu de bai cho
		Box2[x2].push_back(x1); // luu huong mui ten theo chieu nguoc lai
	}
}

void BFS_xuoi (int u){
	queue <int> Q;
	Q.push(u);
	daxet[u] = 1;
	while (!Q.empty()){
		x1 = Q.front(); Q.pop();
		for (int i = 0 ; i < Box1[x1].size() ; i++){
			if (daxet[Box1[x1][i]] == 0){ // chua xet
				daxet[Box1[x1][i]] = 1;
				Q.push(Box1[x1][i]);
			}
		}
	}
}

void BFS_nguoc (int u){
	queue <int> Q;
	Q.push(u);
	daxet[u] = 1;
	while (!Q.empty()){
		x1 = Q.front(); Q.pop();
		for (int i = 0 ; i < Box2[x1].size() ; i++){
			if (daxet[Box2[x1][i]] == 0){ // chua xet
				daxet[Box2[x1][i]] = 1;
				Q.push(Box2[x1][i]);
			}
		}
	}
}

bool IsDuyetHet(){
	for (int i = 1 ; i <= V ; i++){
		if (daxet[i] == 0) return false;
	}
	return true;
}

string LTM(){
	memset(daxet,0,sizeof(daxet));
	BFS_xuoi(1); 
	if (IsDuyetHet() == false) return "NO"; 
	memset(daxet,0,sizeof(daxet));
	BFS_nguoc(1);
	if (IsDuyetHet() == false) return "NO"; 
	return "YES";
}

int main (){
	cin >> T;
	while (T--){
		Box1.clear();
		Box2.clear();
		Input();
		cout << LTM() << endl;
	}
	return 0;
}
