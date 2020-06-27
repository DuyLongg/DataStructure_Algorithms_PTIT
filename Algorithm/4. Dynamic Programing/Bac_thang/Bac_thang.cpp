#include <iostream>
using namespace std;
// L[i] la so cach buoc den bac i
// L[1] = 1 	1
// L[2] = 2 	11   2
// L[3] = 4		111  12  21  3
// L[4] = 8		1111 112 121 211 22 13 31 4

// VD : Cau thang co 5 bac. Dap an can tim la L[5]
// TH1: We dang o bac 4 thi tu bac 4 len bac 5 chi co 1 cach la buoc len 1 buoc => co L[4]*1 cach de di den bac 5
// TH2: We dang o bac 3 thi tu bac 3 len bac 5 chi co 1 cach la buoc len 2 buoc (that ra co 2 cach nhung cach 3+1+1 trung voi cach 4+1 o TH1) => co L[3]*1 cach
// TH3: We dang o bac 2 thi tu bac 2 len bac 5 cung chi co 1 cach la 2+3 (cach 2+1+2 bi trung TH3 va 2+2+1 bi trung TH1) => co L[2]*1 cach
// Tom lai: L[i] = L[i-1]+L[i-2]+...L[i-j] voi j la so buoc toi da co the buoc dc 1 lan 

int main (){
	int T; cin >> T;
	while (T--){
		int N,K;
		cin >> N >> K;
		int L[N+1] = {0};
		L[1] = 1;
		for (int i = 2 ; i <= N ; i++){
			for (int j = 1 ; j <= min(i,K) ; j++) 
				L[i] = (L[i] + L[i-j]) % 1000000007;	// L[i] = L[i-1] + L[i-2] + L[i-so_buoc_toi_da]
			if (i<=K) L[i] = L[i] + 1;
		}
		cout << L[N] << endl;
	}
	return 0;
}
