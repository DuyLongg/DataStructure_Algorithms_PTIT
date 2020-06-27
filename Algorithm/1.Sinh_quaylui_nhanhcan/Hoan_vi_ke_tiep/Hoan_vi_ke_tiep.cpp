#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		vector <int> A;
		int tmp;
		for (int i = 0 ; i < N ; i++) {
			cin >> tmp;
			A.push_back(tmp);
		}
		int vt1,vt2;
		for (int i = N-2 ; i >= 0 ; i--) {
			if (A[i] < A[i+1]) {
				vt1 = i;
				int min = A[i+1];
				vt2 = i+1;
				for (int j = i+2 ; j < N ; j++){
					if (A[j] < min) {
						min = A[j];
						vt2 = j;
					}
				}
				swap (A[vt1],A[vt2]);
				reverse (A.begin()+vt1+1,A.end());
				break;
			}
			if (i==0) for (int i = 0 ; i < N ; i++) A[i] = i+1;
		}
		for (int i = 0 ; i < N ; i++) cout << A[i] << " ";
		cout << endl;
	}
	return 0;
}
