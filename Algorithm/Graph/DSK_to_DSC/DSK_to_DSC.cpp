#include <bits/stdc++.h>
using namespace std;

int N;
string S;
unordered_map <int,vector <int>> U;

void Xuly (int box, string S){
	for (int i = 0 ; i < S.length() ; i++){
		int num = 0;
		while (S[i] != ' ' && i < S.length()){
			num = num * 10 + S[i] - '0';
			i++;
		}
		U[box].push_back(num);
	}
}

int main (){
	cin >> N; cin.ignore();
	for (int i = 1 ; i <= N ; i++){
		getline(cin,S);
		Xuly(i,S);
	}
	for (int i = 1 ; i <= N ; i++){
		for (int j = 0 ; j < U[i].size() ; j++){
			if (U[i][j] > i) cout << i << " " << U[i][j] << endl; // DK de chong in trung
		}
	}
	return 0;
}
