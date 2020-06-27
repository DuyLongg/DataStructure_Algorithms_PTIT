#include <bits/stdc++.h>
using namespace std;
// Note: bai nay phai xet ca truong hop do thi khong lien thong
int T,V,E,x1,x2,P[1005],par; // V la so dinh
unordered_map <int, vector <int>> Box;

void Input (){
	Box.clear();
	cin >> V >> E;
	for (int i = 1 ; i <= E ; i++){
		cin >> x1 >> x2;
		Box[x1].push_back(x2);
		Box[x2].push_back(x1);
	}
}

bool Paint(int i){
	memset(P,-1,sizeof(P)); // tat ca deu chua duoc to mau
	P[i] = 1; // to mau 1 cho dinh 1
	queue <int> Q;
	Q.push(i);
	while (!Q.empty()){
		par = Q.front(); Q.pop();
		for (int i = 0 ; i < Box[par].size() ; i++){
			if (P[Box[par][i]] == -1){ // dinh ke chua duoc to mau
				P[Box[par][i]] = 1 - P[par]; // gan cho dinh ke mau khac voi mau cua node cha
				Q.push(Box[par][i]);
			} else if (P[Box[par][i]] == P[par]) return false; // neu mau cua node con da duoc to va giong mau cua nut cha
		}
	}
	return true;
}

string TPLT (){
	for (int i = 1 ; i <= V ; i++){
		if (P[i] = -1) {
			if (!Paint(i)) return "NO";
		}
	}
	return "YES";
}

int main (){
	cin >> T;
	while (T--){		
		Box.clear();
		Input();
		cout << TPLT() << endl;
	}
	return 0;
}
