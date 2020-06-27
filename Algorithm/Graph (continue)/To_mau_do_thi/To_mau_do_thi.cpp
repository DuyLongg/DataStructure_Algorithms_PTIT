#include <bits/stdc++.h>
using namespace std;

int T,V,E,M,x1,x2,P[105],par; // V la so dinh
// P[i] = 0 - dinh i chua to mau
//		= 1 - dinh i to mau thu nhat
//		= N - dinh i to mau thu n
unordered_map <int, vector <int>> Box;

void Input (){
	Box.clear();
	cin >> V >> E >> M;
	for (int i = 1 ; i <= E ; i++){
		cin >> x1 >> x2;
		Box[x1].push_back(x2);
		Box[x2].push_back(x1);
	}
}

bool ktra (int i, int mau){
	for (int j = 0 ; j < Box[i].size() ; j++){ /// duyet tat ca dinh ke cua dinh i xem co cai nao cung mau khong
		if (P[Box[i][j]] == mau) return false; // trung
	}
	return true; // khong trung
}

string Paint (){
	memset(P,0,sizeof(P));
	int colored = 0;
	int mau = 0;
	while (colored != V){
		mau++; // su dung 1 loai mau danh dau tat ca cac dinh co the
		for (int i = 1 ; i <= V ; i++){
			if (P[i] == 0 && ktra(i,mau)){ // neu dinh i chua duoc to mau va cac dinh ke khong co mau nao giong mau dinh gan
				P[i] = mau;
				colored++;
			}
		}
	}
	if (mau <= M) return "YES";
	else return "NO";
}

int main (){
	cin >> T;
	while (T--){		
		Input();
		if (M >= 4) cout << "YES" << endl;
		else cout << Paint() << endl;
	}
	return 0;
}
