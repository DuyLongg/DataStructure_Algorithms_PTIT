#include <bits/stdc++.h>
using namespace std;
// ( ( ) ) ) ( ) (
// 0 1 2 3 4 5 6 7
//       |
//		 \          
// (())()(
// ()())((
// )())((
// (())()
long long dem = 0;
void del (string S, long long last_bracket, long long first_bracket, char A, char B){
	for (long long count = 0, i = last_bracket ; i < S.length() ; i++){
		if (S[i] == A) count++;
		if (S[i] == B) count--;
		if (count >= 0) continue;
		for (long long j = first_bracket ; j <= i ; j++){
			if (S[j] == B && (j == first_bracket || S[j-1] != B)) {
				del (S.substr(0,j)+S.substr(j+1),i,j,A,B);
			}
		}
		return;
	}
	string tmp = S;
	reverse (tmp.begin(),tmp.end());
	if (A == '(') del (tmp,0,0,')','(');
	else {
		if (tmp.size() > 1) {
			dem++;
			cout << tmp << " ";
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
