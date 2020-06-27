#include <bits/stdc++.h>
using namespace std;

int t,S,T,kq[10005],tmp,tmp2;

void Solve(){
	memset(kq,-1,sizeof(kq));
	kq[S] = 0;
	queue <int> A;
	A.push(S);
	while (!A.empty()){
		tmp = A.front(); A.pop();
		tmp2 = tmp-1;
		if (kq[tmp2] == -1){
			kq[tmp2] = kq[tmp] + 1;
			if (tmp2 == T) break;
			A.push(tmp2);
		}
		tmp2 = tmp * 2;
		if (kq[tmp2] == -1){
			kq[tmp2] = kq[tmp] + 1;
			if (tmp2 == T) break;
			A.push(tmp2);
		}
	}
}

int main (){
	cin >> t;
	while (t--){
		cin >> S >> T;
		Solve();
		cout << kq[T] << endl;
	}
	return 0;
}
