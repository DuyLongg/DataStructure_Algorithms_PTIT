#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T,N;

int main (){
	cin >> T;
	while (T--){
		cin >> N;
		queue <ll> A;
		A.push(1);
		while (A.front() % N != 0){
			ll tmp = A.front();
			A.pop();
			A.push(tmp*10);
			A.push(tmp*10+1);
		}
		cout << A.front() << endl;
	}
	return 0;
}
