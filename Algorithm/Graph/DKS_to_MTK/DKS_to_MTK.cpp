#include <bits/stdc++.h>
using namespace std;

int N,A[1005][1005];
string S;

void Xuly (int id, string S){
	for (int i = 0 ; i < S.length() ; i++){
		int num = 0;
		while (S[i] != ' ' && i < S.length()){
			num = num * 10 + S[i] - '0';
			i++;
		}
		A[id][num] = 1;
	}
}

int main (){
	cin >> N; cin.ignore();
	for (int i = 1 ; i <= N ; i++){
		getline(cin,S);
		Xuly(i,S);
	}
		
	for (int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= N ; j++){
			cout << A[i][j] << " ";
		} cout << endl;
	}
	return 0;
}
