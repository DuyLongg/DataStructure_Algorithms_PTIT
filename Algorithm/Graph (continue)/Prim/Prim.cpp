#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int j,w; // dinh cuoi va trong so
};

bool operator > (const Edge &A, const Edge &B){
	return A.w > B.w;
}

int T,V,E,x,y,w,ans,daxet[10005];
typedef priority_queue <Edge, vector<Edge>, greater<Edge>> MinHeap;	// luu tap canh cau (canh cau la canh noi giua SNT va phan do thi chua duoc xet)
typedef vector<vector<Edge>> Graph;

int Prim(const Graph &g){
	memset(daxet,0,sizeof(daxet));
	ans = 0;
	MinHeap heap;
	heap.push({1,0}); // dua dinh 1 vao heap
	while (!heap.empty()){
		while (!heap.empty() && daxet[heap.top().j]) heap.pop();
		if (heap.empty()) break;
		Edge e = heap.top(); heap.pop();
		daxet[e.j] = 1;
		ans += e.w;
		for (Edge e: g[e.j]) heap.push(e);
	}
	return ans;
}

int main (){
	cin >> T;
	while (T--){
		cin >> V >> E;
		Graph g(V+1);
		for (int i = 1 ; i <= E ; i++){
			cin >> x >> y >> w;
			g[x].push_back({y,w}); 
			g[y].push_back({x,w});
		}
		cout << Prim(g) << endl;
	}
	return 0;
}
