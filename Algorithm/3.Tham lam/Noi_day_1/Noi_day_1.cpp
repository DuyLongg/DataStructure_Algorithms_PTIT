#include <iostream>
#include <queue>
using namespace std;

inline void Set (priority_queue <int, vector<int>, greater<int> > &a,int N){
	int b;
	for (int i = 0 ; i < N ; i++){
		cin >> b;
		a.push(b);
	}
}

int main (){
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		priority_queue <int, vector<int>, greater<int> > a;
		Set(a,N);
		long long fee = 0,tmp1,tmp2;
		N--;
		while (N--){
			tmp1 = a.top(); a.pop();
			tmp2 = a.top(); a.pop();
			fee = fee + tmp1 + tmp2;
			a.push(tmp1+tmp2);
		}
		cout << fee << endl;
	}
	return 0;
}
