#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,X,sum = 0,dem = 0;
vector <int> A;
vector <int> kq;

void In (){
	cout << "[";
	for (int i = 0 ; i < kq.size()-1 ; i++)
		cout << kq[i] << " ";
	cout << kq[kq.size()-1] << "] ";
	dem++;
}

void Try (int r){
	for (int i = r ; i < A.size() ; i++){
		sum = sum + A[i];
		kq.push_back(A[i]);
		if (sum==X) In();
		else if (sum + A[i] <= X) Try(i);
		kq.pop_back();
		sum = sum - A[i];
	}
}

int main (){
	int T; cin >> T;
	while (T--){
		cin >> N >> X;
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
