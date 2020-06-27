#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T,K;
string S;

int main (){
	cin >> T;
	while(T--){
		cin >> K >> S;
		ll N = S.length();
		if (K >= N) {
			cout << 0 << endl;
			continue;
		}
		priority_queue <ll> pq;
		ll ts[300] = {0};
		for (int i = 0 ; i < N ; i++) ts[S[i] - 'A']++;
		for (int i = 0 ; i < 300 ; i++) pq.push(ts[i]);
		while (K--){
			int tmp = pq.top(); pq.pop();
			pq.push(--tmp);
		}
		ll kq = 0;
		while (!pq.empty()){
			kq = kq + pq.top()*pq.top();
			pq.pop();
		}
		cout << kq << endl;
	}
	return 0;
}
