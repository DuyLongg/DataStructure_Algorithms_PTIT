#include <bits/stdc++.h>
using namespace std;

int t,S,T,dem,tmp;
vector <int> SNT;
vector <int> DSK[10000];
int kq[10000],daxet[10000];

void Sang (){
	int A[10000] = {0};
	for (int i = 2 ; i < 10000 ; i++){
		if (A[i] == 0){
			if (i > 1000) SNT.push_back(i);
			for (int j = 2 ; i*j < 10000 ; j++) A[i*j] = 1;
		}
	}
}

bool SS (int A, int B){
	dem = 0;
	while (A != 0){
		if (A%10 != B%10) dem++;
		A = A/10; B = B/10;
	}
	return dem == 1;
}

void Init(){
	for (int i = 0 ; i < SNT.size()-1 ; i++){
		for (int j = i+1 ; j < SNT.size() ; j++){
			if (SS(SNT[i],SNT[j])){ // tra ve true la lech nhau 1 so
				DSK[SNT[i]].push_back(SNT[j]);
				DSK[SNT[j]].push_back(SNT[i]);
			}
		}
	}
}

int BFS (){
	memset (daxet,0,sizeof(daxet));
	memset (kq,-1,sizeof(kq));
	if (S == T) return 0;
	queue <int> A;
	A.push(S);
	kq[S] = 0;
	daxet[S] = 1; // true
	while (!A.empty()){
		tmp = A.front(); A.pop();
		for (int i = 0 ; i < DSK[tmp].size() ; i++){
			if (daxet[DSK[tmp][i]] == 0){ // chua xet
				if (DSK[tmp][i] == T) {
					return kq[tmp]+1;
				}
				A.push(DSK[tmp][i]);
				daxet[DSK[tmp][i]] = 1;
				kq[DSK[tmp][i]] = kq[tmp] + 1;
			}
		}
	}
}

int main (){
	cin >> t;
	Sang ();
	Init();
	while (t--){
		cin >> S >> T;
		cout << BFS() << endl;;
	}
	return 0;
}
