#include <bits/stdc++.h>
using namespace std;

int T;
string S;

int main (){
	cin >> T;
	while (T--){
		cin >> S;
		stack <char> A;
		int i;
		for (i = 0 ; i < S.size() ; i++){
			if (S[i] == '(' || S[i] == '[' || S[i] == '{') A.push(S[i]);
			else {
				if (!A.empty() && (S[i]-1 == (int) A.top() || S[i]-2 == (int) A.top())){
					A.pop();
				} else break;
			}
		}
		if (A.empty() && i == S.size()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
