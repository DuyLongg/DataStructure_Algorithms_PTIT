#include <bits/stdc++.h>
#define ll long long
#define vocuc 100000000
using namespace std;

int T,V,E,u,v,w,d[1005],p[1005];
// d[v] luu chi phi nho nhat tam thoi cua duong di tu s toi v
// p[] de truy vet
ll A[1005][1005]; // MT ke

void Input(){
	cin >> V >> E; // s la dinh bat dau
	for (int i = 1 ; i <= V ; i++){
		for (int j = 1 ; j <= V ; j++) 
			A[i][j] = INT_MAX;	
	}
	for (int i = 1 ; i <= E ; i++){
		cin >> u >> v >> w;
		A[u][v] = w;
	}	
}

void Bellman_Ford(){
	// khoi tao d[] = INT_MAX
	for (int i = 1 ; i <= V ; i++) d[i] = INT_MAX;
	memset(p,0,sizeof(p));
	// duyet tat ca canh dinh ke cua s 
	d[1] = 0; p[1] = 1;
	for (int i = 1 ; i <= V ; i++){
		if (A[1][i] < INT_MAX){ // co canh noi s voi i
			d[i] = A[1][i];
			p[i] = 1;
		}
	}
	// ***********
	for (int i = 1 ; i <= V-2 ; i++){
		for (int n = 1 ; n <= V ; n++){
			for (int m = 1 ; m <= V ; m++){
				if (d[m] > d[n] + A[n][m]){ // tim canh bi cang
					d[m] = d[n] + A[n][m]; // gian canh cang 
					p[m] = n;
				}
			}
		}
	}
	// Kiem tra chu trinh am
	for (int i = 1 ; i <= V ; i++){
		for (int j = 1 ; j <= V ; j++){
			if (d[j] > d[i] + A[i][j]) { // co chu trinh am
				cout << 1 << endl;
				return;
			}
		}
	}
	cout << 0 << endl;
}

int main (){
	cin >> T;
	while (T--){
		Input();
		Bellman_Ford();
	}
	return 0;
}
