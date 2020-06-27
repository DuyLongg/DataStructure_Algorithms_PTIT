#include <bits/stdc++.h>
using namespace std;

int T,V,E,x1,x2,Time;
int daxet[10005];
unordered_map <int,vector<int>> Box;
vector <pair<int,int>> Cau;

void Input (){
	cin >> V >> E;
	for (int i = 1 ; i <= E ; i++){
		cin >> x1 >> x2;
		Box[x1].push_back(x2);
		Box[x2].push_back(x1);
	}
}

int D[10005]; // luu thoi diem duoc duyet cua moi phan tu
int L[10005]; // la thoi diem cua phan tu dau tien da duyet duoc tim thay boi DFS

void DFS (int v, int p){
	daxet[v] = 1;
	D[v] = L[v] = Time++;
	for (int i = 0 ; i < Box[v].size() ; i++){
		if (Box[v][i] == p) continue;
		if (daxet[Box[v][i]]) L[v] = min (L[v], D[Box[v][i]]);
		else {
			DFS (Box[v][i], v);
			L[v] = min (L[v], L[Box[v][i]]);
			if (L[Box[v][i]] > D[v]) {
				if (v < Box[v][i]) Cau.push_back(make_pair(v,Box[v][i]));
				else Cau.push_back(make_pair(Box[v][i],v));
			}
		}
	}
}

void CanhCau (){
	Time = 0;
	memset(daxet,0,sizeof(daxet));
	memset(D,-1,sizeof(D));
	memset(L,-1,sizeof(L));
	DFS(1,-1);
	sort (Cau.begin(),Cau.end());
	for (int i = 0 ; i < Cau.size() ; i++){
		cout << Cau[i].first << " " << Cau[i].second << " ";	
	}
}

int main (){
	cin >> T;
	while (T--){
		Box.clear(); Cau.clear();
		Input();
		CanhCau();
		cout << endl;
	}
	return 0;
}
