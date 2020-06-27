#include <bits/stdc++.h>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		double N,S,M; cin >> N >> S >> M;
		if ((M*7) <= (N*6)) cout << ceil(S*M/N) /*+ floor (ceil((S*M/N))/7)*/ << endl;
		else  cout << -1 << endl;
	}
	return 0;
}
