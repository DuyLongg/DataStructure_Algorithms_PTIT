#include <bits/stdc++.h>
using namespace std;

int T,V,E,x1,x2,bacle;
unordered_map <int,vector<int>> Box;

void Input (){
	cin >> V >> E;
	for (int i = 1 ; i <= E ; i++){
		cin >> x1 >> x2;
		Box[x1].push_back(x2);
		Box[x2].push_back(x1);
	}
}

int Solve (){
	bacle = 0;
	for (int i = 1 ; i <= V ; i++){
		if (Box[i].size() % 2) bacle++;
	}
	if (bacle == 0) return 2; // la do thi Euler
	if (bacle == 2) return 1; // la do thi nua Euler
	return 0; // khong la gi ca
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
