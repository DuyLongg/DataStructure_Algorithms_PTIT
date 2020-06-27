#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N,K,M,u,v,x,y,daxet[10005][10005]; 
// K la so dinh (so con cuu)
struct node{
	ll i,j;
};
node key;
node V[10005]; // luu toa do cac dinh
set <ll> DN; // DeathNote

void Input (){
	DN.clear();
	cin >> N >> K >> M;
	for (int i = 1 ; i <= M ; i++){ 
		cin >> u >> v >> x >> y;
		DN.insert(u*1000+v*100+x*10+y);
		DN.insert(x*1000+y*100+u*10+v);
	//	cout << "A = " << u*1000+v*100+x*10+y << endl;
	//	cout << "B = " << x*1000+y*100+u*10+v << endl;
	}
	for (int i = 1 ; i <= K ; i++){
		cin >> V[i].i >> V[i].j;
	}
}

ll dem;

ll CoCuu(int x,int y){
	for (int i = 1 ; i <= K ; i++){
		if (x == V[i].i && y == V[i].j) return 1; // co cuu
	}
	return 0;
}

ll BFS (node A){
	dem = 0;		// so cuu vua tim duoc
	queue <node> Q;
	Q.push(A);
	if (CoCuu(A.i,A.j)) dem++;
	daxet[A.i][A.j] = 1;
	while (!Q.empty()){
		key = Q.front(); Q.pop();
		x = key.i-1; y = key.j;
		if (x >= 1 && !daxet[x][y] && !DN.count(key.i*1000+key.j*100+x*10+y)){
			Q.push({x,y});
			daxet[x][y] = 1;
			if (CoCuu(x,y)) dem++;
		//	cout << "tren" << endl;
		}
		x = key.i+1; y = key.j;
		if (x <= N && !daxet[x][y] && !DN.count(key.i*1000+key.j*100+x*10+y)){
			Q.push({x,y});
			daxet[x][y] = 1;
			if (CoCuu(x,y)) dem++;
		//	cout << "duoi" << endl;
		}		
		x = key.i; y = key.j-1;
		if (y >= 1 && !daxet[x][y] && !DN.count(key.i*1000+key.j*100+x*10+y)){
			Q.push({x,y});
			daxet[x][y] = 1;
			if (CoCuu(x,y)) dem++;
		//	cout << "trai" << endl;
		}		
		x = key.i; y = key.j+1;
		if (y <= N && !daxet[x][y] && !DN.count(key.i*1000+key.j*100+x*10+y)){
			Q.push({x,y});
			daxet[x][y] = 1;
			if (CoCuu(x,y)) dem++;
		//	cout << "phai" << endl;
		}
	}
	return dem;
}

ll Cuu (){
	ll kq = 0;
	ll seen = 0;
	memset(daxet,0,sizeof(daxet));
	for (int i = 1 ; i <= K ; i++){
		if (!daxet[V[i].i][V[i].j]){
		//	cout << "[i,j] = " << "[" << V[i].i << ", " << V[i].j << "]" << endl;
			ll r = BFS(V[i]);
			seen += r;
			kq = kq + r*(K-seen);
		//	cout << "r = " << r << endl;
		//	cout << "K-seen = " << K-seen << endl;
		//	cout << "new = " << r*(K-seen) << endl;
		}
	}
	return kq;
}

int main (){
	Input();
	cout << Cuu() << endl;
	return 0;
}
