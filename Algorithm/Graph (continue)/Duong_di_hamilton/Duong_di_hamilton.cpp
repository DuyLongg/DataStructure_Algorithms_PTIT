#include <bits/stdc++.h>
using namespace std;

int T,V,E,x1,x2,MT[15][15],Permu[15];

void Input(){
	memset(MT,0,sizeof(MT));
	cin >> V >> E; // dinh - canh
	for (int i = 1 ; i <= E ; i++){
		cin >> x1 >> x2;
		MT[x1][x2] = MT[x2][x1] = 1;
	}
}

bool IsHamilton(){
	for (int i = 1 ; i < V ; i++){
		if (!MT[Permu[i]][Permu[i+1]]) return false; // khong phai hamilton
	}
	return true;
}

int PathHamil (){
	for (int i = 1 ; i <= V ; i++) Permu[i] = i;
	do{
		if (IsHamilton()) return 1; // co hamiton
	} while (next_permutation(Permu+1,Permu+1+V));
	return 0;
}

int main (){
	cin >> T;
	while (T--){
		Input();
		cout << PathHamil() << endl;
	}
	return 0;
}
