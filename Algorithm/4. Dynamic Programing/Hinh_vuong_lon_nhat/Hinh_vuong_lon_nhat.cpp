#include <iostream>
using namespace std;

void Nhap (int N, int M, int A[][500], int L[][500]){
	for (int i = 0 ; i < N ; i++){
		for (int j = 0 ; j < M ; j++){
			cin >> A[i][j];
			L[i][j] = A[i][j];
		}
	}
}

int main (){
	int T; cin >> T;
	while (T--){
		int N,M,FOPT=0;
		cin >> N >> M; // N la hang, M la cot
		int A[500][500];
		int L[500][500]; // la kich thuoc hinh vuong lon nhat xuat phat tu diem co toa do i,j (chinh la A[i][j]) khoi tao no = voi mang A[N][M]
		Nhap (N,M,A,L);
		for (int i = 0 ; i < N ; i++){
			for (int j = 0 ; j < M ; j++){
				if (A[i][j]){
					for (int r = 1 ; i+r < N && j+r < M ; r++){
						if (A[i+r][j+r]){
							for (int c = 1 ; c <= r ; c++){
								if (A[i+r][j+r-c]==0 || A[i+r-c][j+r]==0) {
									r = N;
									break;
								}
							}
							if (r < N) L[i][j] = L[i][j] + 1;
						} else break;
					}
				}
				if (L[i][j] > FOPT) FOPT = L[i][j];
			}
		}
		if (FOPT==1) cout << 0 << endl;
		else cout << FOPT << endl;
	}
	return 0;
}
