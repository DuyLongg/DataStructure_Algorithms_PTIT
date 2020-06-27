#include <bits/stdc++.h>
using namespace std;

int T,N,tmp,M;

int main (){
	cin >> T;
	while (T--){
		cin >> N; // luong truy van
		queue <int> Q;
		while (N--){
			cin >> M;
			if (M == 1){
				cout << Q.size() << endl;
			} else if (M == 2){
				if (Q.empty()) cout << "YES" << endl;
				else cout << "NO" << endl;
			} else if (M == 3){
				cin >> tmp;
				Q.push(tmp);
			} else if (M == 4){
				if (!Q.empty()) Q.pop();
			} else if (M == 5){
				if (Q.empty()) cout << -1 << endl;
				else cout << Q.front() << endl;
			} else if (M == 6){
				if (Q.empty()) cout << -1 << endl;
				else cout << Q.back() << endl;
			}
		}
	}
	return 0;
}
