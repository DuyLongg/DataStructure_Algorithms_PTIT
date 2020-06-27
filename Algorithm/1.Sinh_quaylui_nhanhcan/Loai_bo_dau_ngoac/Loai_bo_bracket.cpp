#include <bits/stdc++.h>
using namespace std;
// (()))()(
// (())()(
// ()())((
// )())((
// (())()

int dem = 0;
void del (string S, int last_bracket, int first_bracket, char A, char B){
	int count = 0; 
	int i = last_bracket;
	while (i < S.length() && count >= 0){
		if (S[i] == A) count++;
		if (S[i] == B) count--;
		i++;
	}
	if (count >= 0) {
		reverse(S.begin(),S.end());
		if (A == '(') del (S,0,0,')','(');
		else {
			if (S.size() > 1) {
				dem++;
				cout << S << " ";
			}
		}
	} else {
		i = i - 1;
		for (int j = first_bracket ; j <= i ; j++){
			if (S[j] == B && (j == first_bracket || S[j-1] != B)){
				del (S.substr(0,j)+S.substr(j+1),i,j,A,B);
			}
		}
	}
}

int main (){
	int T; cin >> T;
	while (T--){
		string S; cin >> S;
		del (S,0,0,'(',')');
		if (dem == 0) cout << -1;
		cout << endl;
		dem = 0;
	}
	return 0;	
} 
