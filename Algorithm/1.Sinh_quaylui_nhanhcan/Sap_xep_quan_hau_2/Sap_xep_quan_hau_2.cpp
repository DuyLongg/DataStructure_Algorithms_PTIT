#include <iostream>
using namespace std;

int cot[8];
int cheotrai[15];
int cheophai[15];
int b[8][8];
int FOPT = 0;
int tong = 0;
void Try (int i){
	for (int j = 0 ; j < 8 ; j++){
		if(cot[j] == 0 && cheophai[i+j] == 0 && cheotrai[7-i+j] == 0){
			cot[j] = 1;		
			cheophai[i+j] = 1;
			cheotrai[7-i+j] = 1;
			tong = tong + b[i][j];
			if (i==7) {
				if (tong > FOPT) FOPT = tong;
			} else Try(i+1);
			cot[j] = 0;
			cheophai[i+j] = 0;
			cheotrai[7-i+j] = 0;
			tong = tong - b[i][j];
		}
	}
}

int main (){
	int T = 0;
	cin >> T;
	while (T--){
		for (int i = 0 ; i < 8 ; i++){
			for (int j = 0 ; j < 8 ; j++){
				cin >> b[i][j];
			}
		}
		Try(0);
		cout << FOPT << endl;
		FOPT = 0;
	}
	return 0;
}

