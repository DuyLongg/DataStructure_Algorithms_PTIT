#include <bits/stdc++.h>
using namespace std;

int T,V,E,x1,x2,daxet[1005],tmp;
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

void DFS_xuoi (int u){
	daxet[u] = 1;
	for (int i = 0 ; i < Box1[u].size() ; i++){
		if (daxet[Box1[u][i]] == 0){ // dinh ke chua xet
			DFS_xuoi(Box1[u][i]);
		}
	}
}

void DFS_nguoc (int u){
	daxet[u] = 1;
	for (int i = 0 ; i < Box2[u].size() ; i++){
		if (daxet[Box2[u][i]] == 0){ // dinh ke chua xet
			DFS_nguoc(Box2[u][i]);
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
	DFS_xuoi(1); 
	if (IsDuyetHet() == false) return "NO"; 
	memset(daxet,0,sizeof(daxet));
	DFS_nguoc(1);
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
