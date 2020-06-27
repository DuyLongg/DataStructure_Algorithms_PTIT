#include <iostream>
#include <vector>
using namespace std;

int N,dem=0;
int A[11][11], B[11][11] = {0};// 0 la chua chon
vector <char> C;

void Input (){
	for (int i = 0 ; i < N ; i++){
		for (int j = 0 ; j < N ; j++){
			cin >> A[i][j];
		}
	}
}

void In(){
	for (int i = 0 ; i < C.size() ; i++) cout << C[i];
	cout << " ";
	dem++;
}

void Try (int i, int j){
	if (A[i+1][j] && B[i+1][j]==0){
		B[i+1][j] = 1;
		C.push_back('D');
		Try (i+1,j);
		C.pop_back();
		B[i+1][j] = 0;
	} 
	if (A[i][j+1] && B[i][j+1]==0){
		B[i][j+1] = 1;
		C.push_back('R');
		Try(i,j+1);
		C.pop_back();
		B[i][j+1] = 0;
	}
	if (i==N-1 && j==N-1) In();
}

int main (){
	int T; cin >> T;
	while (T--){
		cin >> N;
		Input ();
		if (A[0][0]) Try(0,0);
		if (dem==0) cout << -1;
		cout << endl;
		dem = 0;
	}
	return 0;
}
