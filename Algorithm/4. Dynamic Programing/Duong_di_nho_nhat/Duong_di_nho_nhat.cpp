//  L[i][j] luu gia tri duong di nho nhat tu (1,1) den (i,j) 
//  Vi chi co the di chuyen sang phai, xuong duoi, cheo duoi nen de di duoc toi (i,j) chi co 3 con duong:
//  Do la : (i-1,j) -> (i,j) la truong hop di tu tren duong duoi
// 			(i,j-1) -> (i,j) la truong hop di tu phai sang trai
//			(i-1,j-1) -> (i,j) la truong hop di cheo duoi
// => Duong di co gia tri nho nhat se tim duoc neu xet 3 duong di tren va chon 1 duong di co gia tri nho nhat
//	  khi do duong co gia tri nho nhat khi di tu (1,1) -> (i,j) se la L[i][j] = min (L[i-1][j],L[i][j-1],L[i-1][j-1]) + A[i][j];

#include <iostream>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int N,M; cin >> N >> M;
		int A[N][M];
		int L[N][M];
		for (int i = 0 ; i < N ; i++)
			for (int j = 0 ; j < M ; j++) cin >> A[i][j];
		for (int i = 0 ; i < N ; i++){
			for (int j = 0 ; j < M ; j++){
				if (i==0 && j==0) L[0][0] = A[0][0];
				else if (i==0) L[0][j] = L[0][j-1] + A[0][j];
				else if (j==0) L[i][0] = L[i-1][0] + A[i][0];
				else L[i][j] = min(min(L[i][j-1], L[i-1][j]), L[i-1][j-1]) + A[i][j];
			}
		}
		cout << L[N-1][M-1] << endl;	
	}
	return 0;
}
