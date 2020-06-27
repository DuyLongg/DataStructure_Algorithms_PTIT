#include <bits/stdc++.h>
using namespace std;
// de bai gioi han bi sai so canh <= 10k moi dung
struct canh{
	int w;
	int i,j;	// i,j la 2 dau cua canh va w la trong so
};

int Par[1005];
int T,N,M;	// N la so dinh va M la so canh
canh E[10005]; // E la tap canh va MSP la viet tat cua Minimum Spanning Tree

void Input (){
	cin >> N >> M;
	for (int i = 1 ; i <= M ; i++){
		cin >> E[i].i >> E[i].j >> E[i].w;
	}
}

int root(int u){
	return (Par[u] < 0) ? u : (Par[u] = root(Par[u])); // ki thuat nen duong di
}

bool merge(int u, int v){
	if ((u = root(u)) == (v = root(v))) return false; // cung 1 cay the khong the merge duoc	
	if (Par[u] > Par[v]) swap (u,v); // cay y lon hon cay x thi dao lai de cay x lon hon cay y
	Par[u] += Par[v]; // so phan tu tren cay sau khi ghep 2 cay con thanh 1 cay lon
	Par[v] = u; // ghep cay
	return true; // merge thanh con
}

bool rule (canh A, canh B) {
	return A.w < B.w;
}

void Kruskal (){
	memset(Par,-1,sizeof(Par)); // reset 
	int MinVal = 0;
	sort (E+1, E+M+1, rule);
	for (int r = 1 ; r <= M ; r++){ // duyet tap canh
		if (merge(E[r].i, E[r].j)){
	//		cout << "Canh[" << r << "] = " << E[r].i << " " << E[r].j << endl;
			MinVal += E[r].w;
		}
	}
	cout << MinVal << endl;
}

int main (){
	cin >> T;
	while (T--){
		Input();
		Kruskal();		
	}
	return 0;
}
