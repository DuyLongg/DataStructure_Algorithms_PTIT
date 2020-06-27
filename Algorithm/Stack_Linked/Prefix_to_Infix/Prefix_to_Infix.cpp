#include <bits/stdc++.h>
using namespace std;

int T;
string S;

int main (){
	cin >> T;
	while (T--){
		cin >> S;
		int N = S.length();
		stack <string> A;
		for (int i = N-1 ; i >= 0 ; i--){
			if (S[i] >= 'A' && S[i] <= 'Z') A.push(string(1,S[i]));
			else {
				string op1 = A.top(); A.pop();
				string op2 = A.top(); A.pop();
				A.push("(" + op1 + S[i] + op2 + ")");
			}
		}
		cout << A.top() << endl;
	}
	return 0;
}
