#include <bits/stdc++.h>
using namespace std;

int Q,x;
string S;

int main (){
	cin >> Q;
	deque <int> DQ;
	while (Q--){
		cin >> S;
		if (S == "PUSHFRONT"){
			cin >> x;
			DQ.push_front(x);
		} else if (S == "PRINTFRONT"){
			if (DQ.empty()) cout << "NONE" << endl;
			else cout << DQ.front() << endl;
		} else if (S == "POPFRONT"){
			if (!DQ.empty()) DQ.pop_front();
		} else if (S == "PUSHBACK"){
			cin >> x;
			DQ.push_back(x);
		} else if (S == "PRINTBACK"){
			if (DQ.empty()) cout << "NONE" << endl;
			else cout << DQ.back() << endl;
		} else {
			if (!DQ.empty()) DQ.pop_back();
		}
	}
	return 0;
}
