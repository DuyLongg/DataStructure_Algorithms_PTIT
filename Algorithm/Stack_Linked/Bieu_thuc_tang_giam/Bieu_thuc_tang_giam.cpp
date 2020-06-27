#include <bits/stdc++.h>
using namespace std;

int T;
string S;

int main (){
	cin >> T;
	while (T--){
		cin >> S;
		stack <int> A;
		A.push(1);
		int N = S.length();
		for (int i = 0 ; i < N ; i++){
			if (S[i] == 'D') A.push(A.top()+1);
			else {
				int min = A.top()+1;
				while (!A.empty()) {
					cout << A.top();
					A.pop();
				}
				A.push(min);
			}
		}
		while (!A.empty()){
			cout << A.top();
			A.pop();
		}
		cout << endl;
	}
	return 0;
}
