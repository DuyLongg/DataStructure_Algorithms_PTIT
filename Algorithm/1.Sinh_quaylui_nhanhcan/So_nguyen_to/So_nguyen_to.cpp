#include <iostream>
#include <vector>
using namespace std;

int N,P,S,sum=0,dem=0;
int A[201] = {0};
vector <int> B;
vector <int> kq;
vector <int> C;

void Sang (){
	for (int i = 2 ; i <= S ; i++){
		if (A[i]==0){
			if (i >= P) B.push_back(i);
			for (int j = 2 ; i*j <= S ; j++){
				A[i*j] = 1;
			}
		}
	}
}

void Try (int r,int step){
	for (int i = r ; i < B.size() ; i++){
		sum = sum + B[i];
		kq.push_back(B[i]);
		if (sum == S && step == N) {
			dem++;
			for (int i = 0 ; i < kq.size() ; i++) C.push_back(kq[i]);
		}
		if (step < N && sum + B[i+1] <= S) Try (i+1,step+1);
		kq.pop_back();
		sum = sum - B[i];
	}
}

void In (){
	cout << dem << endl;
	int count = 0;
	for (int i = 0 ; i < C.size() ; i++){
		count++;
		cout << C[i] << " ";
		if (count == N) {
			cout << endl;
			count = 0;
		}
	}
}

int main (){
	int T; cin >> T;
	while (T--){
		cin >> N >> P >> S;
		Sang();
		Try (0,1);
		In();
		dem = 0;
		B.clear(); C.clear();
	}
	return 0;
}
