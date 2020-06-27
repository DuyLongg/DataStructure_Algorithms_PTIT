#include <bits/stdc++.h>
#define ll long long
#define vocuc 100000000
using namespace std;

int T,V,E,s,u,v,w,d[1005],p[1005];
// d[v] luu chi phi nho nhat tam thoi cua duong di tu s toi v
// p[] de truy vet
ll A[1005][1005]; // MT ke

void Input(){
	cin >> V >> E >> s; // s la dinh bat dau
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
	d[s] = 0; p[s] = s;
	for (int i = 1 ; i <= V ; i++){
		if (A[s][i] < INT_MAX){ // co canh noi s voi i
			d[i] = A[s][i];
			p[i] = s;
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
				cout << -1 << endl;
				return;
			}
		}
	}
	// In ra kq theo thu tu tang dan dinh
	for (int i = 1 ; i <= V ; i++){
		if (d[i] > vocuc) cout << "INFI "; 
		// chu y khong dung duoc d[i] < INT_MAX vi INT_MAX la 1 so cu the khong phai vo cung nen khi tinh toan co the thay doi gia tri cua no
		// vi du: +vocung - 7 = +vocung nhung INT_MAX - 7 = INT_MAX - 7;
		else cout << d[i] << " ";
	}
	cout << endl;
}

int main (){
	cin >> T;
	while (T--){
		Input();
		Bellman_Ford();
	}
	return 0;
}
