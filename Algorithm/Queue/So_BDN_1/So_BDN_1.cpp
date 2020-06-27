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
		ll count = 0;
		while (A.front() <= N){
			count++;
			ll tmp = A.front();
			A.pop();
			A.push(tmp*10);
			A.push(tmp*10+1);
		}
		cout << count << endl;
	}
	return 0;
}
