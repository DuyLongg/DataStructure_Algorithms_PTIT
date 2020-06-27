#include <bits/stdc++.h>
using namespace std;

int T,N;

struct node {
	int data;
	int bac;
};

int Solve (){
	node tmp;
	set <int> have;
	have.insert(N);
	queue <node> A;
	A.push({N,0});
	while (!A.empty()){
		tmp = A.front(); A.pop();
		if (tmp.data == 2) return tmp.bac+1;
		if (have.count(tmp.data-1) == 0) {
			have.insert(tmp.data-1);
			A.push({tmp.data-1, tmp.bac+1});
		}
		for (int i = 2 ; i*i <= tmp.data ; i++){
			if (tmp.data % i == 0){
				if (have.count(tmp.data/i) == 0) {
					have.insert(tmp.data/i);
					A.push({tmp.data/i,tmp.bac+1});
				}
			}
		}
	}
}

int main (){
	cin >> T;
	while (T--){
		cin >> N;
		cout << Solve() << endl;
	}
	return 0;
}
