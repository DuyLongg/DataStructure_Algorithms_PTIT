#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int SinhHV(vector <int> &A){
	int pic1,pic2;
	for (int i = A.size()-2 ; i >= 0 ; i--){
		if (A[i] < A[i+1]){
			pic1 = i;
			int min = A[i+1];
			pic2 = i+1;
			for (int j = i+2 ; j < A.size() ; j++){
				if (A[j] > A[pic1] && A[j] < min) {
					min = A[j];
					pic2 = j;
				}
			}
			swap(A[pic1],A[pic2]);
			reverse(A.begin()+pic1+1,A.end());
			return 1;
		}
	}
	return 0;
}

int main (){
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		vector <int> A;
		for (int i = 0 ; i < N ; i++) {
			A.push_back(i+1);
			cout << N-A[i]+1;
		} cout << " ";
		while (SinhHV(A)){
			for (int i = 0 ; i < N ; i++) cout << N-A[i]+1;
			cout << " ";
		}
		cout << endl;
	}
	return 0;
}
