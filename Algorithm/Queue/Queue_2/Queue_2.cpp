#include <bits/stdc++.h>
using namespace std;

int T,x;
string S;

int main (){
	cin >> T; // T la so luong truy van
	queue <int> Q;
	while (T--){
		cin >> S;
		if (S == "PUSH"){
			cin >> x;
			Q.push(x);
		} else if (S == "PRINTFRONT"){
			if (Q.empty()) cout << "NONE" << endl;
			else cout << Q.front() << endl;
		} else {
			if (!Q.empty()) Q.pop();
		}
	}
	return 0;
}
