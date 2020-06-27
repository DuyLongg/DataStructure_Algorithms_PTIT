//1 1 1 1
//1 1 1 1 
//1 1 1 1 1
//1 1 1 1 1
//  1 1 1 1

// L[i][j] la kich thuoc hinh vuong lon nhat co dinh duoi phai toa do [i,j]
// Made by TDL
#include <iostream>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int N,M,FOPT=0;
		cin >> N >> M;
		int A[N][M]={0};
		int L[N][M]={0};
		for (int i = 0 ; i < N ; i++){
			for (int j = 0 ; j < M ; j++) cin >> A[i][j];
		}
		for (int i = 0 ; i < N ; i++) L[i][0] = A[i][0];
		for (int j = 0 ; j < M ; j++) L[0][j] = A[0][j];
		for (int i = 1 ; i < N ; i++){
			for (int j = 1 ; j < M ; j++){
				if (A[i][j]) {
					L[i][j] = min(min(L[i-1][j], L[i][j-1]), L[i-1][j-1]) + 1;
					if (L[i][j] > FOPT) FOPT = L[i][j];
				} else L[i][j] = 0;
			}
		}
		cout << FOPT << endl;
	}
	return 0;
}
