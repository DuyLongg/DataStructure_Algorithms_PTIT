#include <bits/stdc++.h>
using namespace std;

int T;
string S;

string Solve (stack <char> &A){
	int N = S.length();
	for (int i = 0 ; i < N ; i++){
		if (S[i] == ')'){
			bool ok = true;
			char tmp = A.top();
			A.pop();
			while (tmp != '('){
				if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/') ok = false;
				tmp = A.top();
				A.pop(); 
			}
			if (ok == true) return "Yes";
		} else A.push(S[i]);
	}
	return "No";
}

int main (){
	cin >> T;
	while (T--){
		cin >> S;
		stack <char> A;
		cout << Solve(A) << endl;
	}
	return 0;
}

