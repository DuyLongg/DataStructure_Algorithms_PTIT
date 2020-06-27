#include <bits/stdc++.h>
using namespace std;
// bai nay gioi han sai 
// thuat toan gan giong prim
// y tuong la tai moi buoc tim canh toi uu de noi 1 cay nay toi 1 cay khac
struct canh{
	int u,v;	// i,j la 2 dau cua canh va w la trong so
	int w;
};

int Par[1005],min_edge[1005];
int T,N,M,r_u,r_v,STP,ans;	// N la so dinh va M la so canh
canh E[10005]; // E la tap canh va MSP la viet tat cua Minimum Spanning Tree

void Input (){
	cin >> N >> M;
	for (int i = 1 ; i <= M ; i++){
		cin >> E[i].u >> E[i].v >> E[i].w;
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

int Boruvka (){
	memset(Par,-1,sizeof(Par)); // reset 
	STP = N; // so thanh phan ban dau bang so dinh
	ans = 0;
	while (STP > 1){ 
		memset (min_edge,-1,sizeof(min_edge)); // min_edge[i] la canh nho nhat noi cay co goc la i toi 1 cay khac 
		// all min_edge = -1 nghia la tat ca cay ban dau deu chua tim duoc canh toi uu
		for (int i = 1 ; i <= M ; i++){ // duyet tap canh
			r_u = root(E[i].u); r_v = root(E[i].v);
			if (r_u == r_v) continue; // cung 1 cay thi bo qua
			if (min_edge[r_u] == -1 || E[i].w < E[min_edge[r_u]].w) min_edge[r_u] = i; // canh nho nhat de noi cay goc r_u sang 1 cay khac la canh i
			if (min_edge[r_v] == -1 || E[i].w < E[min_edge[r_v]].w) min_edge[r_v] = i; // canh nho nhat de noi cay goc r_v sang 1 cay khac la canh i
		}
		for (int i = 1 ; i <= N ; i++){ // duyet tat ca cac dinh
			if (min_edge[i] != -1){	// da tim thay canh toi uu cho cay goc i
				if (merge(E[min_edge[i]].u,E[min_edge[i]].v)){	
					ans += E[min_edge[i]].w;
					STP--;
				}
			}
		}
	}
	return ans;
}

int main (){
	cin >> T;
	while (T--){
		Input();
		cout << Boruvka() << endl;		
	}
	return 0;
}
