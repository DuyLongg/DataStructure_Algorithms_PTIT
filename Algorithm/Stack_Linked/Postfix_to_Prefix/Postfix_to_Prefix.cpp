#include <bits/stdc++.h>
using namespace std;

int T;
string S;

int main (){
	cin >> T;
	while (T--){
		cin >> S;
		stack <string> A;
		int N = S.length();
		for (int i = 0 ; i < N ; i++){
			if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/'){
				string op2 = A.top(); A.pop();
				string op1 = A.top(); A.pop();
				A.push(S[i]+op1+op2);
			} else A.push(string(1,S[i]));
		}
		cout << A.top() << endl;
	}
	return 0;
}
