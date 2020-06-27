#include <bits/stdc++.h>
using namespace std;

int T;
string S;

int findLenMax(){
	int N = S.length();
	stack <int> A;
	A.push(-1);
	int ans = 0;
	for (int i = 0 ; i < N ; i++){
		if (S[i] == '(') A.push(i);
		else {
			A.pop();
			if (!A.empty()) ans = max (ans, i-A.top());
			else A.push(i);
		}
	}
	return ans;
}
int main (){
	cin >> T;
	while (T--){
		cin >> S;
		cout << findLenMax() << endl;
	}
	return 0;
}
