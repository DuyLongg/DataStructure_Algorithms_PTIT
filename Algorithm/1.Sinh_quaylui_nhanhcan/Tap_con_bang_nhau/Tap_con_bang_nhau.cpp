#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,K,sum=0,check=0;
vector <int> kq;
vector <int> A;

void Try (int r){
	for (int j = r ; j < N ; j++){
		if (check==1) break;
		kq.push_back(A[j]);
		sum = sum + A[j];
		if (sum==K) {
			cout << "YES";
			check = 1;
		}
		else if (sum + A[0] <= K) Try (j+1);
		sum = sum - A[j];
		kq.pop_back();
		if (r==0 && j==N-1) cout << "NO";
	}
}

int main (){
	int T; cin >> T;
	while (T--){
		cin >> N;
		int tmp,tong=0;
		for (int i = 0 ; i < N ; i++) {
			cin >> tmp;
			A.push_back(tmp);
			tong = tong + tmp;
		} 
		if (tong%2!=0) {
			cout << "NO";
		} else {
			K = tong/2;
			sort (A.begin(),A.end());
			Try(0);
		}
		cout << endl;
		check = 0;
		A.clear();
	}
	return 0;
}
