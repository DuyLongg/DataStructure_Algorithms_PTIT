/*1	2 	3	4	 5	    6        	7	       		  8   					9	10
A   B  AB  BAB ABBAB BABABBAB  ABBABBABABBAB  	BABABBABABBABBABABBAB
0   1  01  101 01101 10101101  0110110101101	101011010110110101101
							   123456789		123456789
1	1	2	3	5		8			13					21*/
#include <iostream>
using namespace std;

long long fibo[94];

void Sinh_fibo (long long fibo[]){
	fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 1;
	for (int i = 3 ; i <= 93 ; i++){
		fibo[i] = fibo[i-2] + fibo[i-1];
	}
}

void Try (int N, long long i){
	if (N==1) cout << 'A' << endl;
	else if (N==2) cout << 'B' << endl;
	else {
		if (i<=fibo[N-2]){
			Try(N-2,i);
		} else {
			Try (N-1,i-fibo[N-2]);
		}
	}
}

int main (){
	int T; cin >> T;
	while (T--){
		int	N; cin >> N;
		long long i; cin >> i;
		Sinh_fibo(fibo);
		Try (N,i);
	}
	return 0;
}
