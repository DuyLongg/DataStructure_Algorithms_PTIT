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
			cout << "node1 = " << tmp.data-1 << endl;
		}
		int i = sqrt(tmp.data);
		while (tmp.data % i != 0) i++;
		if (tmp.data % i == 0){
			if (have.count(i) == 0) {
				have.insert(i);
				A.push({i,tmp.bac+1});
			}
			cout << "node2 = " << i << endl;
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
