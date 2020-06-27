#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Binary_search (vector <int> &X, int money, int first, int last){
	int mid;
	while (first <= last){
		mid = (first+last)/2;
		if (X[mid] == money) return mid+1;
		else if (X[mid] > money) last = mid-1;
		else first = mid+1;
	}
	return mid;
}

int main (){
	int N; cin >> N;
	vector <int> X;
	int tmp;
	for (int i = 0 ; i < N ; i++) {
		cin >> tmp;
		X.push_back(tmp);
	}
	sort (X.begin(),X.end());
	int Q; cin >> Q;
	int money;
	while (Q--){
		cin >> money;
		cout <<	Binary_search (X,money,0,N-1) << endl;
	}
	return 0;
}
