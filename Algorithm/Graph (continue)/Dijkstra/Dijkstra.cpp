#include <bits/stdc++.h>
using namespace std;
// *Note: Dijkstra dung ma tran ke code dep nhat
int T,V,E,s,u,v,w,A[1005][1005];

struct Dinh{
	int stt; // dinh thu may
	bool k = false;
	int d = INT_MAX; // khoang cach nho nhat tu s den dinh hien tai
	int p = -1; // dinh truoc dinh hien tai tren duong di toi uu
};

void Input(){
	memset(A,-1,sizeof(A));
	cin >> V >> E >> s; // V - so dinh | E - so canh | s la dinh bat dau
	for (int i = 1 ; i <= E ; i++){
		cin >> u >> v >> w;
		// bai nay phai tinh ca truong hop da do thi vo huong
		if (A[u][v] == -1 || A[u][v] > w) // neu canh chua duoc nhap trong so hoac trong so moi nho hon trong so cu ta cap nhat
		A[u][v] = A[v][u] = w;
	}
}

bool operator > (const Dinh &a, const Dinh &b){
	return a.d > b.d;
}

void Dijkstra(){
	// Initialization
	Dinh dinh[V+1];
	for (int i = 1 ; i <= V ; i++) dinh[i].stt = i; // khoi tao cac dinh
	dinh[s].d = 0;
	priority_queue<Dinh, vector<Dinh>, greater<Dinh>> PQ; // tap dinh chua xet
	for (int i = 1 ; i <= V ; i++) PQ.push(dinh[i]); // push tat ca cac dinh chua co dinh vao PQ
	while (!PQ.empty()){
		Dinh next = PQ.top(); PQ.pop(); // trong cac dinh chua xet chon dinh co d[v] nho nhat (tuc la dinh co khoang cach so voi s la ngan nhat)
		if (dinh[next.stt].k == true) continue; // tuc la dinh nay da duoc co dinh roi thi khong xet nua
	//	cout << "min = " << next.d << endl;
		dinh[next.stt].k = true; // co dinh dinh do 
		for (int i = 1 ; i <= V ; i++){ // duyet tat ca ca dinh ke cua dinh next de cap nhat d[v] cua cac dinh ke
			if (A[next.stt][i] != -1 && dinh[i].d > dinh[next.stt].d + A[next.stt][i]){ // neu tim duoc duong di toi uu hon de den dinh i thi cap nhat
				dinh[i].d = dinh[next.stt].d + A[next.stt][i]; // cap nhat chi phi toi uu hon cho dinh i
				dinh[i].p = next.stt; // va luc nay phan tu truoc cua i tren duong di toi uu la next
				Dinh newD; newD.stt = i; newD.k = false; newD.d = dinh[i].d; newD.p = dinh[i].p;
				PQ.push(newD);
			}
		}
	}
	for (int i = 1 ; i <= V ; i++) cout << dinh[i].d << " ";
	cout << endl;

}

int main (){
	cin >> T;
	while (T--){
		Input();
		Dijkstra();
	}
	return 0;
}
