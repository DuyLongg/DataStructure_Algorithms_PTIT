#include <bits/stdc++.h>
#define ll long long
using namespace std;

int T;
string S;

ll pri (char a){
	if (a == '*' || a == '/') return 2;
	else if (a == '+' || a == '-') return 1;
	else return 0;
}

ll Cal (stack <ll> &TH, stack <char> &TT){
	ll op2 = TH.top(); TH.pop();
	ll op1 = TH.top(); TH.pop();
	if (TT.top() == '+') TH.push(op1+op2);
	else if (TT.top() == '-') TH.push(op1-op2);
	else if (TT.top() == '*') TH.push(op1*op2);
	else TH.push(op1/op2);
	TT.pop();
}

int main (){
	cin >> T;
	while (T--){
		cin >> S;
		stack <ll> TH;
		stack <char> TT;
		ll N = S.length();
		for (ll i = 0 ; i < N ; i++){
			if (S[i] == ' ') continue;
			if (S[i] == '(') TT.push('(');
			else if (S[i] == ')') {
				while (!TT.empty() && TT.top() != '(') Cal(TH,TT);
				if (!TT.empty()) TT.pop();
			} else if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/'){
				while (!TT.empty() && (pri(S[i]) <= pri(TT.top()))) Cal (TH,TT);
				TT.push(S[i]);				
			} else {
				if (i == 0 || (S[i-1] < '0' || S[i-1] > '9')) TH.push(S[i]-'0');
				else {
					ll tmp = TH.top(); TH.pop();
					TH.push(tmp*10+S[i]-'0');
				}	
			}
		}
		while (!TT.empty()) Cal (TH,TT);
		cout << TH.top() << endl;
	}
	return 0;
}
