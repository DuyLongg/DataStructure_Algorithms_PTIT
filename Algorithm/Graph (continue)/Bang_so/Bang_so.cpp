#include <bits/stdc++.h>
using namespace std;

struct node{
	int x,y; // toa do 
	int cost;
};

int T,N,M,A[505][505];

void Input(){
	cin >> N >> M;
	for (int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= M ; j++){
			cin >> A[i][j];
		}
	}
}

bool operator < (const node &A, const node &B){
	if (A.cost == B.cost){ // neu chi phi bang nhau 
		if (A.x != B.x) return A.x < B.x; 
		else return A.y < B.y;
	}
	return A.cost < B.cost; // sap xep trong set theo cost
}

bool Inside (int i, int j){ // xem phan tu co nam trong ma tran khong
	return (i >= 1 && i <= N && j >= 1 && j <= M);
}

int dist[505][505]; 

int Dijkstra(){
	memset(dist,0,sizeof(dist));
	// ma tran CAP NHAT chi phi dung de luu chi phi nho nhat tam thoi cua duong di tu A[1][1] cho den khi di den d[i][j]
	for (int i = 1 ; i <= N ; i++){
		for (int j = 1; j <= M ; j++){
			dist[i][j] = INT_MAX;
		}
	}
	dist[1][1] = A[1][1];
  	int dx[] = {-1,0,1,0}; // dung de xu ly bon phia
    int dy[] = {0,1,0,-1};	
    set <node> st;
    st.insert({1,1,A[1][1]}); // dua phan tu [1,1] vao set
    while (!st.empty()){
    	node k = *st.begin();
    	st.erase(st.begin());
    	for (int i = 0 ; i < 4 ; i++){
    		int x = k.x + dx[i]; // kiem tra 4 phan tu xung quanh
            int y = k.y + dy[i]; 
			if (!Inside(x,y)) continue;
			if (dist[x][y] > dist[k.x][k.y] + A[x][y]){ // neu tim duoc duong di nho hon thi cap nhat
				if (dist[x][y] != INT_MAX) st.erase(st.find({x, y, dist[x][y]})); 
				// xet xem dist[x][y] da tung duoc cap nhat chua neu roi thi phai xoa lan cap nhat cu trong set di
				dist[x][y] = dist[k.x][k.y] + A[x][y]; 
                st.insert({x, y, dist[x][y]});
			}
		}
	}
	return dist[N][M];
}

int main (){
	cin >> T;
	while (T--){
		Input();
		cout << Dijkstra() << endl;
	}
	return 0;
}
