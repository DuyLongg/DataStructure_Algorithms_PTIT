#include <bits/stdc++.h>
using namespace std;

int T;
string S;

int main (){
	cin >> T;
	while (T--){
		cin >> S;
		stack <int> A;
		int N = S.length();
		for (int i = N-1 ; i >= 0 ; i--){
			if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/'){
				int op1 = A.top(); A.pop();
				int op2 = A.top(); A.pop();	
				if (S[i] == '+') A.push(op1+op2);
				else if (S[i] == '-') A.push(op1-op2);
				else if (S[i] == '*') A.push(op1*op2);
				else A.push(op1/op2);
			} else A.push(S[i]-'0');
		}
		cout << A.top() << endl;
	}
	return 0;
}
