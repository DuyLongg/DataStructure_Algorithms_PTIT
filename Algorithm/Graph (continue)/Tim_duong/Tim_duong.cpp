#include <bits/stdc++.h>
using namespace std;

int T,N,M,daxet[505][505],x,y,new_level;
char A[505][505];

struct node{
	int i,j; // toa do node tren ma tran
	int level; // la so lan chuyen huong
};

node F; // node dau
node key; // key la node trung gian

void Input(){
	cin >> N >> M;
	for (int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= M ; j++){
			cin >> A[i][j];
			if (A[i][j] == 'S') {F.i = i; F.j = j;} // cap nhat toa do nut dau
		}
	}
}

string Find_Path(){
	memset (daxet,0,sizeof(daxet));
	F.level = 0;
	queue <node> Q;
	Q.push(F);
	daxet[F.i][F.j] = 1; // danh dau phan tu bat dau la da xet
	while (!Q.empty()){
		key = Q.front(); Q.pop();
		if (A[key.i][key.j] == 'T') {
			if (key.level <= 3) return "YES"; // dang nhe nho <= 2 nhung ma tinh thua 1 lan chuyen huong nen la cho <= 3;
			else return "NO";
		}
		new_level = key.level+1;
		x = key.i+1; y = key.j;
		while (A[x][y] != '*' && !daxet[x][y] && x <= N){
			Q.push({x,y,new_level});
			daxet[x][y] = 1;
			x++;
		}
		x = key.i-1; y = key.j;
		while (A[x][y] != '*' && !daxet[x][y] && x >= 1){
			Q.push({x,y,new_level});
			daxet[x][y] = 1;
			x--;
		}		
		x = key.i; y = key.j+1;
		while (A[x][y] != '*' && !daxet[x][y] && y <= M){
			Q.push({x,y,new_level});
			daxet[x][y] = 1;
			y++;
		}		
		x = key.i; y = key.j-1;
		while (A[x][y] != '*' && !daxet[x][y] && y >= 1){
			Q.push({x,y,new_level});
			daxet[x][y] = 1;
			y--;
		}
	}
	return "NO";
}

int main (){
	cin >> T;
	while (T--){
		Input();
		cout << Find_Path() << endl;
	}
	return 0;
}
