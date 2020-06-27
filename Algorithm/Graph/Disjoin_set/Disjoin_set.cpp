#include <bits/stdc++.h>
using namespace std;

int T,V,E,parent[1005];
pair <int,int> A[500005];
bool cycle;

void Input(){
	memset (parent,-1,sizeof(parent));
	cin >> V >> E;
	for (int i = 1 ; i <= E ; i++){
		cin >> A[i].first >> A[i].second;
	}
}

int find (int parent[], int x){
	if (parent[x] == -1) return x;
	return find(parent,parent[x]);
}

void Union (int parent[], int x1, int x2){
	parent[x1] = x2;
}

void Disjoint(){
	for (int i = 1 ; i <= E ; i++){
		int x1 = find (parent,A[i].first);
		int x2 = find (parent,A[i].second);
		if (x1 == x2) {
			cycle = true;
			return;
		}
		Union(parent, x1, x2);
	}
}

int main (){
	cin >> T;
	while (T--){
		cycle = false;
		Input();
		Disjoint();
		if (cycle == true) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
