#include <bits/stdc++.h>
using namespace std;

int T;
string S;

int pri (char ope){
	if (ope == '^') return 3;
	else if (ope == '*' || ope == '/') return 2;
	else if (ope == '+' || ope == '-') return 1;
	else return -1;
}

void In_to_Post(){
	stack <char> A;
	for (int i = 0 ; i < S.length() ; i++){
		if (S[i] == '(') A.push(S[i]);
		else if (S[i] == ')'){
			while (!A.empty() && A.top() != '('){
				cout << A.top();
				A.pop();
			}
			A.pop();
		} else if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/' || S[i] == '^'){
			while (!A.empty() && pri(A.top()) >= pri(S[i])){
				cout << A.top();
				A.pop();
			}
			A.push(S[i]);
		} else cout << S[i];
	}
	while (!A.empty()){
		if (A.top() != '(') cout << A.top();
		A.pop();
	}
}

int main (){
	cin >> T;
	while (T--){
		cin >> S;
		In_to_Post();
		cout << endl;
	}
	return 0;
}
