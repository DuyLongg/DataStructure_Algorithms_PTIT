#include <bits/stdc++.h>
using namespace std;

int T;
string S;

int Solve(){
	int N = S.size();
	int ans = 0;
	int mode = 0;
	for (int i = 0 ; i < N ; i++){
		if (S[i] == '(') mode++;
		else mode--;
		if (S[i] == ')' && mode < 0){
			ans++;
			mode = 1;
		}
	}
	ans = ans + mode/2;
	return ans;
}

int main (){
	cin >> T;
	while (T--){
		cin >> S;
		cout << Solve() << endl;
	}
	return 0;
}
