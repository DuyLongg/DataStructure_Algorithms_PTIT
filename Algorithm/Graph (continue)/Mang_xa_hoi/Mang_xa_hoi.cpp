#include <bits/stdc++.h>
using namespace std;
// do thi day du
int T,N,M,x,y,daxet[100005],ans,ele;
unordered_map <int,vector<int>> Box;

void Input(){
	cin >> N >> M;
	for (int i = 1 ; i <= M ; i++){
		cin >> x >> y;
		Box[x].push_back(y);
		Box[y].push_back(x);
	}
}

int DFS (int u){
	int kq = 1;
	daxet[u] = 1;
	for (int i = 0 ; i < Box[u].size() ; i++){
		if (!daxet[Box[u][i]]){
			kq += DFS(Box[u][i]);
		}
	}
	return kq;
}

string Facebook(){
	ans = 0;	// tong so canh can co de moi TPLT la day du
	memset(daxet,0,sizeof(daxet));
	for (int i = 1 ; i <= N ; i++){
		if (!daxet[i]){
			ele = DFS(i); // so canh can co de moi TPLT la do thi day du
			ans += ele*(ele-1)/2;
		}
	}
	if (ans == M) return "YES";
	else return "NO";
}

int main (){
	cin >> T;
	while (T--){
		Box.clear();
		Input();
		cout << Facebook() << endl;
	}
	return 0;
}
