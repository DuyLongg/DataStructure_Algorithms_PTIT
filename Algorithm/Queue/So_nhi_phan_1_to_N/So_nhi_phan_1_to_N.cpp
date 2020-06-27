#include <bits/stdc++.h>
using namespace std;

int T,N;

int main (){
	cin >> T;
	while (T--){
		cin >> N;
		queue <string> Q;
		Q.push("1");
		while (N--)	{
			string S = Q.front();
			cout << S << " ";
			Q.pop();
			Q.push(S+"0");
			Q.push(S+"1");
		}
		cout << endl;
	}
	return 0;
}
