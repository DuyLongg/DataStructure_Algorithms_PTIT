/*1 2 3 4 5 6
1 5 3 4 2 6
1 5 2 4 3 6
1 5 2 4 6 3
1 5 2 4 6 3

1 2 3 4 5 6
4 2 3 1 5 6
4 1 3 2 5 6
4 1 3 5 2 6
4 1 3 5 2 6*/

#include <bits/stdc++.h>
using namespace std;

struct node{
	int khoi[7];
	int level;
};

node BD,D,temp,node_XT,node_XP;// node ban dau va node dich
vector <node> daxet;

int SS (node A, node B){
	for (int i = 1 ; i <= 6 ; i++){
		if (A.khoi[i] != B.khoi[i]) return 0;
	}
	return 1;
}

node XT (node A){   // ham xoay hinh vuong ben  trai
	swap (A.khoi[1],A.khoi[4]);
	swap (A.khoi[2],A.khoi[4]);
	swap (A.khoi[4],A.khoi[5]);
	return A;
}

node XP (node A){	// ham xoay hinh vuong ben phai
	swap (A.khoi[2],A.khoi[5]);
	swap (A.khoi[3],A.khoi[5]);
	swap (A.khoi[5],A.khoi[6]);
	return A;
}

int ktra (node A){
	for (int i = 0 ; i < daxet.size() ; i++){
		if (SS(A,daxet[i])) return 1;
	}
	return 0;
}

int BFS(){
	queue <node> A;
	A.push(BD);
	daxet.push_back(BD);
	BD.level = 0;
	while (!A.empty()){
		temp = A.front(); A.pop();
		if (SS(temp,D)) return temp.level; // so sanh 2 node voi nhau tra ve 1 tuc la 2 node giong nhau
		node_XT = XT(temp); // node xoay hinh vuong ben trai 
		if (ktra(node_XT) == 0){ // ktra node xoay trai da duoc xet chua neu chua tra ve 0
			daxet.push_back(node_XT);
			node_XT.level = temp.level + 1;
			A.push(node_XT);
		}
		node_XP = XP(temp); // node xoay hinh vuong ben phai
		if (ktra(node_XP) == 0){ // ktra node xoay phai da duoc xet chua neu chua tra ve 0
			daxet.push_back(node_XP);
			node_XP.level = temp.level + 1;
			A.push(node_XP);
		}
	}
}

int main (){
	for (int i = 1 ; i <= 6 ; i++) cin >> BD.khoi[i];
	for (int i = 1 ; i <= 6 ; i++) cin >> D.khoi[i];
	cout << BFS();
	return 0;
}

