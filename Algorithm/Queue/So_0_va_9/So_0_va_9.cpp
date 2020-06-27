#include <bits/stdc++.h>
#define ll long long
using namespace std;

int T,N;

int main (){
	cin >> T;
	while (T--){
		cin >> N;
		queue <ll> A;
		A.push(9);
		while (A.front() % N != 0){
			ll tmp = A.front();
			A.pop();
			A.push(tmp*10);
			A.push(tmp*10+9);
		}
		cout << A.front() << endl;
	}
	return 0;
}
