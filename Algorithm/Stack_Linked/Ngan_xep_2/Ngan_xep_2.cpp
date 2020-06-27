#include <bits/stdc++.h>
using namespace std;
 
int Q,val;
string S;
stack <int> A;
 
int main (){
	cin >> Q;
	while (Q--){
		cin >> S;
		if (S == "PUSH"){
			cin >> val;
			A.push(val);
		} else if (S == "POP" && !A.empty()){
			A.pop();
		} else if (S == "PRINT"){
			if (A.empty()) cout << "NONE" << endl;
			else cout << A.top() << endl;
		}
	}
	return 0;
}
