#include <bits/stdc++.h>
using namespace std;

int T;
string P1,P2;

string change (string S){
		int N = S.length();
		stack <char> A,B;
		for (int i = 0 ; i < N ; i++){
			if (S[i] == ')'){
				char tmp = A.top();
				A.pop();
				while (!A.empty() && tmp != '('){
					B.push(tmp);
					tmp = A.top();
					A.pop();
				}
				if (!A.empty() && A.top() == '-') {
					while (!B.empty()){
						char tmp2 = B.top(); B.pop();
						if (tmp2 == '+') tmp2 = '-';
						else if (tmp2 == '-') tmp2 = '+';
						A.push(tmp2);
					}
				} else {
					while (!B.empty()){
						char tmp1 = B.top();
						A.push(tmp1); 
						B.pop();
					}
				}
			} else A.push(S[i]);
		}
		string tmp = "";
		while (!A.empty()) {
			tmp = A.top() + tmp;
			A.pop();
		}
	return tmp;
}

int main (){
	cin >> T;
	while (T--){
		cin >> P1;
		cin >> P2;
		P1 = change(P1);
		P2 = change(P2);
		if (P1.compare(P2) == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
