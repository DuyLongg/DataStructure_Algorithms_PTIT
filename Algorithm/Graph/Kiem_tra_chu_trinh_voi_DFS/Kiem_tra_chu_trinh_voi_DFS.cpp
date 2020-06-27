#include <bits/stdc++.h>
using namespace std;

int T,V,E,x1,x2,daxet[1005],truoc[1005],tmp;
unordered_map <int, vector <int>> Box;

void Input(){
	cin >> V >> E;
	for (int i = 1 ; i <= E ; i++){
		cin >> x1 >> x2;
		Box[x1].push_back(x2);
		Box[x2].push_back(x1);
	}
}

string DFS (int u){
	stack <int> A;
	A.push(u);
	daxet[u] = 1;
	while (!A.empty()){
		tmp = A.top(); A.pop();
		for (int i = 0 ; i < Box[tmp].size() ; i++){
			cout << "daxet[" << Box[tmp][i] << "] = " << daxet[Box[tmp][i]] << " | truoc[" << tmp << "] = " << truoc[tmp] << endl;
			if (daxet[Box[tmp][i]] == 1 && Box[tmp][i] != truoc[tmp]) return "YES";
			if (daxet[Box[tmp][i]] == 0){
				truoc[Box[tmp][i]] = tmp;
				daxet[Box[tmp][i]] = 1;
				A.push(tmp); A.push(Box[tmp][i]);
				break;
			}
		}
	}
	return "NO";
}

int main (){
	cin >> T;
	while (T--){
		memset(truoc,0,sizeof(truoc));
		memset(daxet,0,sizeof(daxet));
		Box.clear();
		Input();
		cout << DFS(1) << endl;
	}
	return 0;
}
