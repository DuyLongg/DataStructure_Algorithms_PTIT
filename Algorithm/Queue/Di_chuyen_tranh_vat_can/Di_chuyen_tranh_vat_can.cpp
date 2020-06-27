#include <bits/stdc++.h>
using namespace std;

int N,a,b,c,d,t;
char A[105][105];
int daxet[105][105];

void Input(){
	cin >> N; // N la kich thuoc ma tran
	for (int i = 0 ; i < N ; i++){
		for (int j = 0 ; j < N ; j++){
			cin >> A[i][j];
		}
	}	
	cin >> a >> b >> c >> d; // Toa do diem xuat phat
}

struct node{
	int i,j;
	int level; // toa do;
};

node temp;

int BFS (){
	memset (daxet,0,sizeof(daxet));
	node BD,D; // node ban dau va node dich
	BD.i = a; BD.j = b; D.i = c; D.j = d;
	BD.level = 0; // so buoc de di tu vi tri BD den vi tri BD la 0
	queue <node> B;
	B.push(BD);
	daxet[a][b] = 1; // toa do dau tien da xet
	while (!B.empty()){
		temp = B.front(); B.pop();
//		cout << "i = " << temp.i << " | j = " << temp.j << " | level = " << temp.level << endl;
		if (temp.i == D.i && temp.j == D.j) return temp.level;
		// xet theo hang
		t = 1;
		while (temp.j+t < N && A[temp.i][temp.j+t] != 'X' && daxet[temp.i][temp.j+t] == 0){
			B.push({temp.i,temp.j+t,temp.level+1});
			daxet[temp.i][temp.j+t] = 1;
			t++;
		}
		t = 1;
		while (temp.j-t >= 0 && A[temp.i][temp.j-t] != 'X' && daxet[temp.i][temp.j-t] == 0){
			B.push({temp.i,temp.j-t,temp.level+1});
			daxet[temp.i][temp.j-t] = 1;
			t++;
		}
		// xet theo cot
		t = 1;
		while (temp.i+t < N && A[temp.i+t][temp.j] != 'X' && daxet[temp.i+t][temp.j] == 0){
			B.push({temp.i+t,temp.j,temp.level+1});
			daxet[temp.i+t][temp.j] = 1;
			t++;
		}
		t = 1;
		while (temp.i-t >= 0 && A[temp.i-t][temp.j] != 'X' && daxet[temp.i-t][temp.j] == 0){
			B.push({temp.i-t,temp.j,temp.level+1});
			daxet[temp.i-t][temp.j] = 1;
			t++;
		}		
	}
}

int main (){
	Input();
	cout << BFS() << endl;
	return 0;
}
