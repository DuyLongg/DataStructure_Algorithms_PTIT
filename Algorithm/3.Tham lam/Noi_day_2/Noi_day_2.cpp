#include <iostream>
#include <queue>
#define MOD 1000000007
using namespace std;
int N;
inline void Set (priority_queue <int, vector<int>, greater<int> > &a){
	int b;
	for (int i = 0 ; i < N ; i++){
		cin >> b;
		a.push(b);
	}
}

int main (){
	cin >> N;
	priority_queue <int, vector<int>, greater<int> > a;
	Set(a);
	N--;
	long long fee = 0,tmp1,tmp2;
	while (N--){
		tmp1 = a.top(); a.pop();
		tmp2 = a.top(); a.pop();
		a.push((tmp1+tmp2) % MOD);
		fee = (fee + (tmp1+tmp2) % MOD) % MOD;
	}
	cout << fee;
	return 0;
}
