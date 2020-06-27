#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,K,sum = 0,dem = 0;
vector <int> kq;
vector <int> A;

void In (){
	cout << "[";
	for (int i = 0 ; i < kq.size()-1 ; i++) cout << kq[i] << " ";
	cout << kq[kq.size()-1] << "] ";
	dem++;
}

void Try (int r){
	for (int j = r ; j < N ; j++){
		kq.push_back(A[j]);
		sum = sum + A[j];
		if (sum==K) In();
		else if (sum + A[0] <= K) Try (j+1);
		sum = sum - A[j];
		kq.pop_back();
	}
}

int main (){
	int T; cin >> T;
	while (T--){
		cin >> N >> K;
		int tmp;
		for (int i = 0 ; i < N ; i++) {
			cin >> tmp;
			A.push_back(tmp);
		} 
		sort (A.begin(),A.end());
		Try(0);
		if (dem==0) cout << -1;
		cout << endl;
		dem = 0;
		A.clear();
	}
	return 0;
}
