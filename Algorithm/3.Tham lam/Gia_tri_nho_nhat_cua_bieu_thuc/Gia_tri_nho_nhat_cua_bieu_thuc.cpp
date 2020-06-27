#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		vector <long long> A ;
		vector <long long> B;
		long long tmp;
		for (int i = 0 ; i < N ; i++){
			cin >> tmp; A.push_back(tmp);
		} sort (A.begin(),A.end());
		for (int i = 0 ; i < N ; i++){
			cin >> tmp; B.push_back(tmp);
		} sort (B.begin(),B.end());
		reverse (B.begin(),B.end());
		long long sum = 0;
		for (int i = 0 ; i < N ; i++) sum = sum + A[i]*B[i];
		cout << sum << endl;
	}
	return 0;
}
