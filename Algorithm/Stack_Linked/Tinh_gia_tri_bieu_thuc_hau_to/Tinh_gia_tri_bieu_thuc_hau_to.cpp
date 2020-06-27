#include <bits/stdc++.h>
using namespace std;

int T;
string S;

int main (){
	cin >> T;
	while (T--){
		cin >> S;
		stack <int> A;
		for (int i = 0 ; i < S.size() ; i++){
			if (S[i] >= '0' && S[i] <= '9') A.push(S[i]-'0');
			else {
				int se = A.top(); A.pop();
				int fi = A.top(); A.pop();
				if (S[i] == '+') A.push(fi+se);
				else if (S[i] == '-') A.push(fi-se);
				else if (S[i] == '/') A.push(fi/se);
				else A.push(fi*se);
 			}
		}
		cout << A.top() << endl;
	}
	return 0;
}
