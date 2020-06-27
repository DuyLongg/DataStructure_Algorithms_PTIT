#include <bits/stdc++.h>
using namespace std;

int T,N;

typedef struct point{
	double i,j;
} PNT;

PNT A[105]; // luu tap cac diem
int Par[1005];

struct edge{
	int u,v; // dinh dau va dinh cuoi cua canh
	double cost;
};

vector <edge> C; // tap canh

double dist (int u, int v){ // diem dau && diem cuoi
	return sqrt((A[u].i-A[v].i)*(A[u].i-A[v].i) + (A[u].j-A[v].j)*(A[u].j-A[v].j));
}

bool rule (edge &a, edge &b){
	return a.cost < b.cost;
}

void Preprocess(){ // nhap va xu ly du lieu
	C.clear();
	cin >> N;
	for (int i = 1 ; i <= N ; i++){ 
		cin >> A[i].i >> A[i].j;
	}
	// tao danh sach canh de su dung kruskal
	for (int i = 1 ; i < N ; i++){
		for (int j = i+1 ; j <= N ; j++){
			C.push_back({i,j,dist(i,j)}); // tinh khoang cach tung canh va push vao vector
		}
	}
	sort (C.begin(),C.end(),rule); // sap xep tap canh theo chi phi
}

int root (int u){
	return (Par[u] < 0) ? u : (Par[u] = root(Par[u]));
}

bool merge (int u, int v){
	if ((u = root(u)) == (v = root(v))) return false;
	if (Par[u] > Par[v]) swap(u,v);
	Par[u] += Par[v];
	Par[v] = u;
	return true;
}

void Kruskal (){
	double ans = 0;
	memset(Par,-1,sizeof(Par)); // ban dau tat cac cac diem la rieng le khong co cay nao ca
	for (int i = 0 ; i < C.size() ; i++){
		if (merge(C[i].u,C[i].v)){
			ans += C[i].cost;
		}
	}
	printf ("%.6f\n", ans);
}

int main (){
	cin >> T;
	while (T--){
		Preprocess(); // tien xu ly
		Kruskal();
	}	
	return 0;
}
