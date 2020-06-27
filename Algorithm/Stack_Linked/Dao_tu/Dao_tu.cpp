#include <bits/stdc++.h>
using namespace std;

int T;
string S;

void In (stack <char> &A){
	while (!A.empty()) {
		cout << A.top();
		A.pop();
	} 
	cout << " ";
}

int main (){
	cin >> T;
	cin.ignore();
	while (T--){
		getline(cin,S);	
		int N = S.length();
		stack <char> A;
		int i = 0;
		while (i < N){
			if (S[i] != ' ') A.push(S[i]);
			else In(A);
			i++;
		}
		In(A);
		cout << endl;
	}
	return 0;
}
