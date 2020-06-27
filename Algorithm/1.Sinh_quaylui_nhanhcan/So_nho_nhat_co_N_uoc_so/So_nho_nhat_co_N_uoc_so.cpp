#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
// N = (1+so_lan_xh_SNT) * (1+so_lan_xh_SNT)*...
int a[] = {2,3,5,7,11,13,17,19};
long long FOPT = 9000000000000000000;
int uoc[10];

int checkPrime (int n){
	if (n < 2) return 0;
	for (int i = 2 ; i <= sqrt(n) ; i++){
		if (n%i==0) return 0;
	}
	return 1;
}

double tich = 1;
vector <long long > r;
void Try (int N, int stt){
	if (checkPrime (N)) {
		tich = tich * pow(a[stt], N-1);	
		if(tich < 0) tich = r[stt-1];
		else {
			r.push_back(tich);
			if (tich < FOPT) FOPT = tich;
			if (stt == 0) tich = 1;
			else tich = r[stt-1];
			r.pop_back();				
		}
	} else {
		for (int i = 2 ; i <= N/2 ; i++){
			if (N % i == 0){
				uoc[stt] = i;
				if (stt != 0 && uoc[stt] > uoc[stt-1]) break;
				tich = tich * pow (a[stt],i-1);
				long long can = tich * a[stt+1];
				if (can >= FOPT || can < 0) continue;
				r.push_back(tich);
				Try (N/i,stt+1);
				if (stt == 0) tich = 1;
				else tich = r[stt-1];
				r.pop_back();
			}
		}		
	} 
}

int main (){
	int T = 0;
	cin >> T;
	while (T--){
 		int N = 0;
		cin >> N;
		if (N==1) {
			cout << 1 << endl;
			continue;
		} else {
			Try (N,0);
			cout << FOPT << endl;
		}
		FOPT = 9000000000000000000;
		tich = 1;
	}
	return 0;
}
